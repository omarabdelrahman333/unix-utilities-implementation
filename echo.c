#include <stdio.h>
#include <string.h>


int echo_main(int argc, char *argv[]) {
    	int i=1;
        int remove_newline = 0;
	int enable_escapes = 0;
	while ( i < argc && argv[i][0] == 1 )
	{
		if ( strcmp(argv[i], "-n") == 0)
		{
			remove_newline =1 ;
		}
		else if ( strcmp(argv[i], "-e") ==0)
		{ 
			enable_escapes = 1;
		}
		else if ( strcmp(argv[i], "-E") == 0)
		{
			enable_escapes = 0;
		}	
		else if ( strcmp(argv[i], "-h") == 0 || strcmp(argv[i], "--help") == 0)
		{
		 printf("Usage: echo [OPTION]... [STRING]...\n");
           	 printf("Echo the STRING(s) to standard output.\n\n");
           	 printf("  -n             do not output the trailing newline\n");
           	 printf("  -e             enable interpretation of backslash escapes\n");
           	 printf("  -E             disable interpretation of backslash escapes (default)\n");
           	 printf("  -h, --help     display this help and exit\n");
           	 printf("  -V, --version  output version information and exit\n");
           	 return 0;
		}
         	else if ( strcmp(argv[i], "-V") == 0 || strcmp(argv[i], "--version") == 0 )
		{
		printf("echo version 1.0\n");
            	return 0;
		}
		else
		{	
			break;
		}
			i++;
	}
	

	
	for(; i < argc ; i++)
	{
	 

	printf("%s",argv[i]);
	if( i<argc -1)
		printf(" ");

	}
	if (remove_newline == 0 )
		printf("\n");
	return 0;
}
