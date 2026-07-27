#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>


#define BUF_SIZE 200000

int
main ()
{
 char buf[BUF_SIZE];
int val=0;
  while (1)
    {
      printf ("omar's shell : $ ");
      fflush (stdout);
      if (fgets (buf, BUF_SIZE, stdin) == NULL)
	{
	      	break;
	}



      buf[strlen (buf) - 1] = 0;
      if (strlen (buf) == 0)
	continue;


     		
       if (strncmp (buf, "echo ", 5) == 0)
	    {		
	       printf ("%s\n", buf + 5);
	     
	    }
	    

	  else if (strncmp (buf, "exit ", 4) == 0)
	    {
	      printf ("Good Bye\n");
	      break;
	    }

	  else
	    {
	      printf ("Invalid command\n");
	     val =-1;
	    }


    }
  return val;

}
