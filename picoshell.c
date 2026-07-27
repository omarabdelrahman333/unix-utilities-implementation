#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <unistd.h>
#include <fcntl.h>


#define SIZE_1 4096

int main()
{
   size_t num_chars = 0;
    char *buf = NULL;
    ssize_t size = 0;
    pid_t childpid;
    int val=0;
    while (1) {

	//our command 
	printf("omar's shell : $ ");
	fflush(stdout);
	//using getline function to recieve the user's input and allocate a variable sized memory space inside the heep depending on the input line size
	if ((size = getline(&buf, &num_chars, stdin)) == -1) {
	    break;
	}
	// tokenizing the input so we can divide it into strings (it still points toward the same memory location of the original string but it modifies the string)
	char *piece = strtok(buf, " \n");
	if (piece == NULL) {
	    continue;
	}
	if (strcmp(piece, "exit") == 0) {
	    printf("Good Bye\n");
	    break;
	} else if (strcmp(piece, "cd") == 0) {
	    piece = strtok(NULL, " \n");
	    if (piece == NULL){
		val=1;
	    	continue;
	    }
		else if (chdir(piece) < 0 ) {
	printf("cd: %s: No such file or directory\n", piece);
		val=1;
		continue;
	    }
		else{
		val=0;
		continue;
		}
	}
	// implementing the echo utility
	else if (strcmp(piece, "echo") == 0) {

	    piece = strtok(NULL, " \n");
	    while (piece != NULL) {
		printf("%s", piece);

		piece = strtok(NULL, " \n");
		if (piece != NULL) {
		    printf(" ");

		} 	    
	    }

	    printf("\n");
	    val=0;
	    continue;
	    
	} 
	 else if (strcmp(piece, "pwd") == 0) {
	    char *buf2=getcwd(NULL,0);
	    if (buf2 == NULL) {
		val=1;
		continue;
	    }

	    printf("%s\n", buf2);
	    free(buf2);
	    val=0;
	    continue;

	}
	//creating a new process 
	childpid = fork();
	//parent process (our shell)     
	if (childpid > 0) {
	    int status;
	    wait(&status);
	    if(WIFEXITED(status))
		    val=WEXITSTATUS(status);
	}
	//child process(the utility)
	else if (childpid == 0) {
	    char *args[100];
	    int i = 0;
	    args[i] = piece;
	    i++;
	    piece = strtok(NULL, " \n");
	    while (piece != NULL) {
		args[i] = piece;
		i++;
		piece = strtok(NULL, " \n");
	    }
	    args[i] = NULL;
	    execvp(args[0], args);
	    printf("%s: command not found\n", args[0]);
	    exit(EXIT_FAILURE);
	} else{
	    val=1;
		continue;
	}
    }
    free(buf);
    return val;


}









