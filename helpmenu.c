

#include <stdio.h>
#include <stdlib.h>
#include "helpmenu.h"

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
