// Hex Dump Utility
//
// main.c
//
//
// By: Daniel Dreise - All Rights Reserved 
// October 31, 2019
//
// Modified from Operating Systems - Lab 2

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
	
	FILE *fp;				// File handler (pointer)
	char test[256];			// Variable for file name

	strcpy(test, "test -a ");	// Terminal command to test of file exists
	strcat(test, argv[1]);

	// If the second command line argument is a file & it exists, open it
	if ((argc == 2) & (system(test)==0)){	
		
		char str[256];						// File string. Max 256 characters
		int sz;								// Variable for file size in bytes
		strcpy(str, "hexdump -Cn 160 ");	// Terminal command "hexdump"
		strcat(str, argv[1]);				// concatenated with chosen file to hexdump

		fp = fopen(argv[1], "r");			// open file

		fseek(fp, 0L, SEEK_END);			// find end of the file
		sz = ftell(fp);						// report how many bytes are in file
		rewind(fp);							// return file pointer to begining

		// Indicate file opened
		printf("\n\n********** %s file opened! **********\n\n", argv[1]);	

		system(str);					// Send hexdump command to terminal
		if(sz < 60){					// If file is over 60 bytes, indicate End of File
			printf("\n\nEND OF FILE\n\n");
		}
		

		fclose(fp);								// close file

		// Indicate file closed
		printf("\n\n********** %s file closed! **********\n\n", argv[1]);	

	}
	else {
		// Indicate error if improper arguments used
		fprintf(stderr, "ERROR: Too many arguments or file doesn't exist.\n");	
		system("open /dev/urandom");			// Open /dev/urandom
	}

	return(0);
}