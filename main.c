// pr_args
//
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

#define MAX_FILE_SZ 4294967296		// 4 gb

int main(int argc, char *argv[]) {
	
	FILE *fp;				// File handler (pointer)
	char test[256];			// Variable for file name
	unsigned long int sz;	// Variable for file size in bytes
	char str[256];						// File string. Max 256 characters


	strcpy(test, "test -a ");	// Terminal command to test of file exists
	strcat(test, argv[1]);

	// If the second command line argument is a file & it exists, open it
	if ((argc == 2) & (system(test)==0)){	
		
		sprintf(str, "hexdump -Cn %ld %s", MAX_FILE_SZ, argv[1]);
		printf("%s\n", str);
		//strcpy(str, "hexdump -Cn  160");		// Terminal command "hexdump"
		//strcat(str, MAX_FILE_SZ);
		//strcat(str, " ");
		//strcat(str, argv[1]);				// concatenated with chosen file to hexdump

		fp = fopen(argv[1], "r");			// open file

		fseek(fp, 0L, SEEK_END);			// find end of the file
		sz = ftell(fp);						// report how many bytes are in file
		rewind(fp);							// return file pointer to begining

		// Indicate file opened
		printf("\n\n********** %s file opened! **********\n\n", argv[1]);	

		system(str);			// Send hexdump command to terminal
		if(sz < 60){			// If file is over max file size (bytes), indicate End of File
			printf("\n\nEND OF FILE\n\n");
		}
		

		fclose(fp);								// close file

		// Indicate file closed
		printf("\n\n********** %s file closed! **********\n\n", argv[1]);	

	}
	else {

		strcpy(str, "hexdump -Cn 160");		// Terminal command "hexdump"
		strcat(str, argv[1]);				// concatenated with chosen file to hexdump

		// Indicate error if improper arguments used
		fprintf(stderr, "ERROR: Too many arguments or file doesn't exist.\n");
		fprintf(stderr, "Printing /dev/urandom instead\n");	

		fp = fopen("/dev/urandom", "r");		// Open /dev/urandom

		fseek(fp, 0L, SEEK_END);			// find end of the file
		sz = ftell(fp);						// report how many bytes are in file
		rewind(fp);							// return file pointer to begining

		printf("\n\n********** %s file opened! **********\n\n", argv[1]);	

		system(str);					// Send hexdump command to terminal
		if(sz < MAX_FILE_SZ){					// If file is over max file size (bytes), indicate End of File
			printf("\n\nEND OF FILE\n\n");
		}
		
		fclose(fp);								// close file

		// Indicate file closed
		printf("\n\n********** %s file closed! **********\n\n", argv[1]);

	}

	return(0);
}