/* 							||| iCipher Message |||
 *							-----------------------
 * This is a fun message encoder that uses a simple ASCII shift. Two school
 * age friends could pass 'secret' messages if they each have this application.
 * ----------------------------------------------------------------------------
 * Skills Practiced:
 * -#define constants
 * -struct custom data types
 * -function calls with passed variables
 * -file I/O
 * -Menu Display user interface
 * -Handle user keyboard input
 * -work with switch-case statement
 * -perform ASCII shift
 * -use a flag in a file to limit ASCII sift encryption to a single iteration
 * ----------------------------------------------------------------------------
 * T. Sahlstrom
 * March 2021
 * Updated, May 2021
 *
 */

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Max string length [STRLEN] must be 2 characters more then max message length
 * [MESLEN]. The leading encode flag [encFLAG, which is "#"] and the EOL [\n]
 * must be accomodated.
 *
 */
#define STRLEN 4096 // max string length. Must be 2 characters more than MESLEN
#define MESLEN 4094 // max message length.
#define LENGTH 4096 // for the file buffer
#define FILENAME "MyMessage.txt"

/*
Make my own data type called 'letter'. This is similar to a 'cluster' data
type in LabVIEW
*/
struct letter {
	char message[STRLEN];
	char cipher[STRLEN];
	char fileMsg[STRLEN];
};

struct letter MyLetter;
/* 'MyLetter' of type letter
 * user input is stored in .message
 * the encoded message is stored in .cipher
 * the message passed or read from file is .fileMsg
 */

void readln(char passed_strg[], int maxlen);
// int readln(char passed_strg[], int maxlen);		***original
/* 'readln' processes user input
 * it accepts the passed string and the max length
 * STRLEN constant is used for maxlen
 */

void display();
/* drives the display'
 * updated each iteration of do loop within main()
 */

void *encrypt(char passed[]);
/* encrypts user message from input or from file
 * uses a +2 character ASCII shift
 * writes to file "MyMessage.txt"
 */

void *decrypt(char passed[]);
/* decrypts user message from input or from file
 * performs a -2 character ASCII shift
 * reads file "MyMessage.txt"
 */

char *readFile();
// used by main() to open or create file

void writeFile(char *text);
// writes message to file

int main() {
	char Selection[1];
	int Menu = 0;
	int i = 0;

	system("clear");
	puts("|-------iCipher Message-------|");
	puts("|                             |");
	puts("|--Developed by T. Sahlstrom--|");
	puts("|                             |");
	puts("|---------March, 2021---------|\n");
	puts("Press [ENTER] to continue.");
	getchar();  // wait on user
	readFile(); // file returns value to MyLetter.fileMsg
	strcpy(
		MyLetter.message, MyLetter.fileMsg); // file message to MyLetter.message
	do {									 // Drive Menu
		display();
		// pass max string length because function has to process string with
		// EOL ("/n")
		readln(Selection, STRLEN);
		switch (Selection[0]) {
		case 'n':
		case 'N':
			memset(MyLetter.message, 0, STRLEN); // clear message
			puts("[New Message]\n");
			printf(
				"Max length is (%d) characters. Enter your message now:\n",
				MESLEN);
			// user input message. Must be 1 char < STRLEN to hold place for
			// encryption flag (#)
			readln(MyLetter.message, STRLEN - 1);
			printf("Message reads: \n[%s]\n", MyLetter.message);
			printf("Hit [ENTER] to continue.\n");
			getchar();
			strcpy(
				MyLetter.cipher,
				MyLetter.message); // preserve message, work with cipher.
			// Update .fileMsg because it is used by encrypt/decrypt where file
			// I/O is handled
			strcpy(MyLetter.fileMsg, MyLetter.cipher);
			writeFile(MyLetter.cipher);
			Menu = 0;
			break;
		case 'e':
		case 'E':
			puts("Encrypt\n");
			if (MyLetter.fileMsg[0] != '#') {
				encrypt(MyLetter.cipher);
				Menu = 1;
				break;
			} else {
				Menu = 1;
				break;
			}
		case 'd':
		case 'D':
			puts("Decrypt\n");
			if (MyLetter.fileMsg[0] == '#') {
				decrypt(MyLetter.cipher);
				Menu = 2;
				break;
			} else {
				Menu = 2;
				break;
			}
		case 'q':
		case 'Q':
			puts("Quit\n");
			Menu = 3;
			break;
		default:
			puts("No Selection\n");
			break;
		}
	} while (Menu != 3);
	return 0;
}

// This function is from uDemy lesson
void readln(
	char passed_string[],
	int maxlen) { // STRLEN is passed to maxlen. MESLEN is always less.
	char user_input;
	int i;
	int chars_remain;
	i = 0;			  // set index to 0
	chars_remain = 1; // set at least 1 character
	while (chars_remain) {
		user_input = getchar();   // user types here
		if (user_input == '\n') { // found end of string
			chars_remain = 0;
		} else if (i < maxlen - 1) {
			passed_string[i] = user_input;
			i++;
		}
	}
}

void display() {
	system("clear");
	puts("___________ iCipher ___________\n");
	printf("The Message Reads: \n[%s]\n", MyLetter.cipher);
	puts("_______________________________\n");
	puts("Create New Message..........[N]");
	puts("Run Encryption..............[E]");
	puts("Decrypt Message.............[D]");
	puts("Quit........................[Q]");
	puts("_______________________________");
}

// provied a simple 2-ASCII character shift to 'encode' message
void *encrypt(char passed[]) {
	int i;
	char c;
	char encFLAG[STRLEN + 1] = "#"; // setup encode flag
	puts("Encoding...");
	for (i = 0; i < STRLEN; i++) {
		c = passed[i];
		if (c == ' ') { // skip over the white space
			continue;
		}
		if (c == '\0') { // look for EOL
			break;
		}
		// print characters while encoding
		printf("[%c-->%c]\n", c, MyLetter.cipher[i] = MyLetter.cipher[i] + 2);
	}
	printf("\nThe encoded message is:\n\n[%s]\n", MyLetter.cipher);
	puts("\nHit [ENTER].\n");
	getchar();
	strcat(encFLAG, MyLetter.cipher); // add the encrytion flag to the BEGINNING
									  // of message, stored in encFLAG
	strcpy(MyLetter.fileMsg, encFLAG); // copy encrypted message to fileMsg
	strcpy(MyLetter.cipher, encFLAG);  //***added this with May revision.
	writeFile(MyLetter.fileMsg);	   // write fileMsg to data file
	return 0;
}
void *decrypt(char passed[]) {
	int i;
	char c;
	readFile(MyLetter.cipher);		 // read message from file
	if (MyLetter.cipher[0] == '#') { // if encoded message flag found
		/* This next line ensures only a single decode shift.
		 * It increments the index of .cipher by 1 to strip the flag from the
		 * beginning of the message. Then it copies the message without the flag
		 */
		memmove(
			MyLetter.cipher,
			MyLetter.cipher + 1,
			strlen(MyLetter.cipher));			   // drop flag
		strcpy(MyLetter.fileMsg, MyLetter.cipher); // copy message without flag
	}
	puts("Decoding...");
	for (i = 0; i < STRLEN; i++) {
		c = passed[i];
		if (c == ' ') { // handle spaces
			continue;
		}
		if (c == '\0') { // handle EOL
			break;
		}
		// print characters while decoding
		printf("[%c-->%c]\n", c, MyLetter.cipher[i] = MyLetter.cipher[i] - 2);
	}
	printf("\nThe decoded message is:\n\n[%s]\n", MyLetter.cipher);
	puts("\nHit [ENTER].\n");
	getchar();
	strcpy(
		MyLetter.fileMsg,
		MyLetter.cipher);		 // copy decoded message to file variable
	writeFile(MyLetter.fileMsg); // update file
	return 0;
}
char *readFile() {
	char buff[LENGTH];
	FILE *fp;				   // file pointer
	fp = fopen(FILENAME, "r"); //'r': open to read
	if (fp == 0) {			   // file pointer returned NULL--does not exist
		fp = fopen(FILENAME, "w+"); //'w+': create & open for both read & write
	} else {
		// file already open, get fp contents up to LENGTH, store in buffer
		fgets(buff, LENGTH, fp);
		strcpy(MyLetter.cipher, buff);  // copy buffer contents to .cipher
		strcpy(MyLetter.fileMsg, buff); // copy buffer conents to .fileMsg
	}
	fclose(fp);
	return MyLetter.fileMsg;
}
void writeFile(char *text) {   // Message is passed to 'text'
	FILE *fp;				   // file pointer
	fp = fopen(FILENAME, "w"); // open to write
	fputs(text, fp);		   // write Message 'text' to file
	fclose(fp);				   // close file
}
