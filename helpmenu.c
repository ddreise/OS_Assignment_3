// pr_args
//
// Hex Dump Utility
//
// helpmenu.c
//
//
// By: Daniel Dreise - All Rights Reserved 
// October 31, 2019
//
// Modified from Operating Systems - Lab 2

#include <stdio.h>
#include <stdlib.h>
#include "helpmenu.h"


// Helpmenu output to terminal
void helpmenu (void){

    printf("\n\nhexdumputility: hexdumputility [-d] [-n] filename\n\n"
            
            "	Utility for hexdumping file contents.\n\n"
            
            "	This utility will take a valid file and hex dump the contents. The max\n"
            "	file size in bytes is 4GB. If exceeded, filesize will be truncated.\n"
            "	If the filename is invalid, it will hexdump 60 bytes of /dev/urandom contents\n"
            "	instead\n\n"
            
            "	-d	Hex dumps with corresponding ASCII characters\n\n"
            
            "	-h	Outputs a help menu. Will truncate everything else.\n\n");
	exit(0);
}
