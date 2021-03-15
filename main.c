#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define STRLEN 100  //maximum string length that strlen function will process. Message length must be less than this.
#define MESLEN 10
//STRLEN is passed to maxlen


struct letter {
	char name[STRLEN];
	char password[STRLEN];
	char message[STRLEN];
	char cipher[STRLEN];
};
struct letter MyLetter;

int readln(char passed_strg[], int maxlen);
void * encrypt (char passed[]);
void * decrypt (char passed[]);
void display();

int main() {
	char Selection[1];
	char menuChoice[1];

	int Menu = 0;
	int Length = 0;
	int i = 0;
	int redo = 1;  //redo input loop until message accepted
	
	system("clear");
	puts("|-------iCipher Message-------|");
	puts("|--Developed by T. Sahlstrom--|");
	puts("|---------March, 2021---------|\n\n");
	
		/*	printf("Enter your name:\n");
		readln(MyLetter.name, STRLEN);
		printf("Welcome %s. \n", MyLetter.name);
		printf("Enter the password to continue:\n");
		readln(MyLetter.password, STRLEN);
		printf("< Password Accepted >\n");
	*/	
		
	do{
		display(MyLetter.message);
		readln(Selection, STRLEN);
		switch (Selection[0]) {
			case 'n': case 'N':
				do {
					puts("[New Message]");
					printf("Enter your message now:\n");
					readln(MyLetter.message, STRLEN);
					Length = strlen(MyLetter.message);
					if (Length <= MESLEN) {
						redo = 0;
					}
					else {
						printf("Message Overun. Please try again.\n");
						printf("%d/%d characters used. %d remain.\n", Length, MESLEN, (MESLEN-Length));
						redo = 1;
					}
				} while (redo ==1);
				strcpy(MyLetter.cipher, MyLetter.message); //preserve message, work with cipher.	
				Menu = 0;
				break;
			case 'e': case 'E':
				puts("Encrypt\n");
				encrypt(MyLetter.cipher);
				Menu = 1;
				break;
			case 'd': case 'D':
				puts("Decrypt\n");
				decrypt(MyLetter.cipher);
				Menu = 2;
				break;
			case 'q': case 'Q':
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

//This function is from uDemy lesson
int readln(char passed_strg[], int maxlen) {
	char user_input;
	int i;
	int chars_remain;
	i = 0; 					//set index to 0
	chars_remain = 1;		//set at least 1 character
		while (chars_remain) {
		user_input = getchar();		//user types here
		//found end of string or end of file?
		if ((user_input == '\n') || (user_input == EOF) ) {
			chars_remain = 0;
		} else if (i < maxlen - 1) {
			passed_strg[i] = user_input;
			i++;
		}
	}
	passed_strg[i] = '\0';
	return i;
}
void display() {
	system("clear");
	printf("Original Message: [%s]\n", MyLetter.message);
	printf("Encrypted Message: [%s]\n", MyLetter.cipher);
	puts("________________________");
	puts("Enter New Message....[N]");
	puts("Run Encryption.......[E]");
	puts("Decrypt Message......[D]");
	puts("Quit.................[Q]");
	puts("________________________");
	//printf("Your Message reads: \n$s\n", MyLetter.message);
}
void * encrypt (char passed[]) {
	int i;
	char c;
	char d;
	for (i = 0; i < STRLEN; i++) {
		c = passed[i];
		if (c == ' '){
			continue;
		}
		if (c == '\0') {
			break;
		}
		MyLetter.cipher[i] = MyLetter.cipher[i] + 2;
	}
	return 0;
}
void * decrypt (char passed[]) {
	int i;
	char c;
	for (i = 0; i < STRLEN; i++) {
		c = passed[i];
		if (c == ' '){
			continue;
		}
		if (c == '\0') {
			break;
		}
		MyLetter.cipher[i] = MyLetter.cipher[i] - 2;
	}
	return 0;
}