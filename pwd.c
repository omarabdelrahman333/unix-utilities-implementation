#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int pwd_main() {
   
    char *buf;
       if((buf=  getcwd(NULL ,0)) != NULL )
  {
	printf("%s\n", buf);
        free(buf);
       	return 0;
  }	
       else
  {	       perror("pwd: error retrieving current directory:");


  	  return 1;

  }
}
