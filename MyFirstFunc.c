
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

void main (){

	//this is my first working function with pass and reutrn!
	printf("\nThis is my first function with pass and reutrn.\n\n");
	char userIn[] = "hi";
	concat_funct(userIn);
	printf("---MAIN---\nNew String: %s\n-----------------\n", charOut);

}