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
#include <unistd.h>
#include <getopt.h>
#include "helpmenu.h"

#define MAX_FILE_SZ 4300000000		// ~4 gb
#define MAX_RDM_FILE_SZ 160

int main(int argc, char *argv[]) {
	
	FILE *fp;				// File handler (pointer)
	char test[256];			// Variable for file name
	unsigned long int sz;	// Variable for file size in bytes
	char str[256];			// File string. Max 256 characters
	int option;				// command line flag variable
	int dFLAG = 0;			// ASCII character flag
	int hFLAG = 0;			// Help menu flag

		
	while((option = getopt (argc, argv, "dh")) != -1){		// Checks for command line options
		switch(option)
		{
			case 'd':					// If [-d], set flag to output ASCII characters
				dFLAG = 1;
				break;
			
			case 'h':					// If [-h], set flag to output help menu
				hFLAG = 1;
				break;

			default:
				fprintf(stderr, "Usage: hexdumputility [-d] [-h] filename\n");	// If error detected, output standard error message
				exit(EXIT_FAILURE);
		}
	}

	if( hFLAG == 1)  helpmenu();		// If help menu flag detected, run help menu			

	if( argv[optind] != NULL ) sprintf(test, "test  %s", argv[optind]);	// If first argument is not NULL, ensure filename is actual file

	if ((argc >= 2) & (system(test)==0)){	// If the number of arguments is greater than or equal to 2, and the filename is valid

		if (hFLAG == 1) helpmenu();			// Print help menu
		else;

		// If [-d] flag set, set command line to hexdump ASCII characters
		if (dFLAG == 1) sprintf(str, "hexdump -Cn %ld %s", MAX_FILE_SZ, argv[optind]);
		else (sprintf(str, "hexdump -n %ld %s", MAX_FILE_SZ, argv[optind]));	// If not set, set command line to normal hexdump

		fp = fopen(argv[optind], "r");					// open file

		fseek(fp, 0L, SEEK_END);						// find end of the file
		sz = ftell(fp);									// report how many bytes are in file
		if (sz > MAX_FILE_SZ) sz = MAX_FILE_SZ;			// If file is bigger than 4GB, restrict amount to hexdump
		rewind(fp);										// return file pointer to begining

		printf("\n\n********** %s file opened! **********\n\n", argv[optind]);	// Indicate file opened

		system(str);							// Send hexdump command to terminal
		
		printf("\n\nEND OF FILE\n\n");
		
		fclose(fp);								// close file

		printf("\n\n********** %s file closed! **********\n\n", argv[optind]);	// Indicate file closed

	}


	// If too few arguments or filename is invalid...
	else if ((argc <= 1) | (system(test)!=0)) {

		sprintf(str, "hexdump -n %d /dev/urandom", MAX_RDM_FILE_SZ);	// Set command line argument to hexdump /dev/urandom

		// Indicate error if improper arguments used
		fprintf(stderr, "\nERROR: Too few arguments or file doesn't exist. Hexdumping /dev/urandom instead.\n");

		fp = fopen("/dev/urandom", "r");		// Open /dev/urandom

		printf("\n\n********** /dev/urandom file opened! **********\n\n");	

		system(str);							// Send hexdump command to terminal
		
		printf("\n\nEND OF FILE\n");
		
		fclose(fp);								// close file

		// Indicate file closed
		printf("\n********** /dev/urandom file closed! **********\n\n");

	}


	return(0);
}