#include <stdio.h>


int mv_main(int argc, char *argv[]) {
   
int val;
       	if((val = rename(argv[1],argv[2]))<0)
	{
		perror("couldnt move the file:");
		return -1;
	}




}
