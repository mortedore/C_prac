#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define STRLEN 100  //maximum string length that strlen function will process.
//Message length must be less than this.
// #define MESLEN 10
//This function is from uDemy lesson
//
//STRLEN is passed to maxlen
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

/*
void whilebreak() {
	int i;
	char c;
	char str[50];
	i = 0;
	while( i >= 0 ){
		c = chararray[i];
		printf("[%d]='%c' ", i, c);
		if (c == '!'){
			str[i] = '\0';
			break;
		}
		str[i] = c;
		i++;
	}
	printf("\nAfter while loop, str='%s'", str);
}
void forbreak() {
	int i;
	char str[50];
	char c;
	// for loop #1 - encrypt string
	for( i = 0; i < 50; i++) {		
		c = chararray[i];
		if (c == ' ') {
			str[i] = c;
			continue;
		}
		if (c == '!') {
			str[i] = '\0';
			break;
		}		
		str[i] = chararray[i] + 1;
	}
	printf("Encrypted string is '%s'\n", str);
	
	// for loop #2 - decrypt string
	for( i = 0; i < 50; i++) {		
		c = str[i];
		if (c == ' ') {			
			continue;
		}
		if (c == '\0') {
			break;
		}
		
		str[i] = str[i] - 1;
	}
	printf("Decrypted string is '%s'\n", str);
}
*/
//typedef char Str50[50];
/*
struct letter {
	char name[50];
	char date[10];
	char message[100];
};
struct letter MyLetter;
char testName[30];
*/
char charOut[0];
char * concat_funct(char passed[]){
	char catThis[] = "999";
	printf("Initialized charOut: '%s'\n", charOut);
	printf("---concat_funct---\nPassed string: %s\n", passed);
	printf("Add String: %s\n", catThis);
	strcat(charOut, passed);
	strcat (charOut, catThis);
	printf("New variable to pass back to main: %s\n-----------------\n", charOut); 
	return charOut;
}

int main() {
	//this is my first working function with pass and reutrn!
	printf("\nThis is my first function with pass and reutrn.\n\n");
	char userIn[] = "hi";
	concat_funct(userIn);
	printf("---MAIN---\nNew String: %s\n-----------------\n", charOut);

	printf("Now run getName function:\n");
	char YourName[STRLEN];
	char Password[STRLEN];
	char Message[STRLEN];

	char Select[0];
	int Menu=9;

	//char mess[MESLEN];
	//char *msg;
	int Length = 0;
	int i=0;
	int redo = 1;  //redo input loop until message accepted
	do {
		printf("Enter your name:\n");
		readln(YourName, STRLEN);
		printf("Welcome %s.\n",YourName);
		printf("Enter the password to continue:\n");
		readln(Password, STRLEN);
		printf("< Password Accepted >\nEnter your message now:\n");
		readln(Message, STRLEN);
		//fgets(Message, STRLEN, stdin);
		printf("Your message reads: \n%s\n", Message);
		printf("The length of your message is %d characters.\n", Length = strlen(Message)-1);
		if (Length <= STRLEN)
			{
				printf("Message accepted.\n");
				redo = 0;
			}
		else 
			{
				printf("< Message Overun. Please try again. >\n");
				redo = 1;
			}
		} while (redo == 1);
	do { 
		puts("Run Encryption: [0]");
		puts("Decrypt Message: [1]");
		puts("Quit: [2]");
		readln(Select, STRLEN);
		Menu = atoi(Select); //forgot this at first.
		switch (Menu) {
			case 0:
				puts("Encrypt");
				Menu = 0;
				break;
			case 1:
				puts("Decrypt");
				Menu = 1;
				break;
			case 2:
				puts("Quit");
				Menu = 2;
				break;
			default:
				puts("No Selection");
				break;
			}
		} while (Menu != 2);
	
	
	/*
	if (Select == "Q") 
	{
		puts("Quit");
	} else if (Select == "E") 
	{
		puts("Encrypt");
	} else if (Select =="D") 
	{
		puts("Decrypt");
	}
	*/
	 
	//printf("%s", passName);
	//strcpy(MyLetter.name, passName);
	//printf("The letter contains:\n %s\n, %s\n, %s\n", MyLetter.name, MyLetter.message, MyLetter.date);

	/*char firstname[STRLEN];
	char lastname[STRLEN];
	int len_firstname;
	int len_lastname;

	printf("Enter your first name:");
	len_firstname = readln(firstname, STRLEN);

	printf("Enter your last name:");
	len_lastname = readln(lastname, STRLEN);

	printf("Hello, %s, %s\n", firstname, lastname);
	printf("Length of firstname = %d, lastname = %d", len_firstname, len_lastname);
*/

	//forbreak();
	//whilebreak();
	return 0;
}
