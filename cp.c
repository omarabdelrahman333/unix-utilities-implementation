#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

#define SIZE 4096

int cp_main(int argc, char *argv[]) {
	int fd;
	int fd1;	
	ssize_t bytes_read;
	ssize_t bytes_written;
	char buffer[SIZE];

       	if((fd = open(argv[1], O_RDONLY)) < 0)
	{
		perror("couldnt open source file:");
		return -1;
        }
        
	if((fd1 = open(argv[2], O_WRONLY| O_CREAT | O_TRUNC , 0666)) < 0)
	{
		perror("couldnt open destination file:");
		return -1;
        }

	while( (bytes_read =read(fd,buffer,SIZE)) >0)
	{
     
         	bytes_written = write(fd1, buffer, bytes_read);  
	   
		if(bytes_written != bytes_read)
	 	       	{
			perror("cp: write error");
			close(fd);
			close(fd1);
			return 1;	
		
	   		}		

	}
close(fd);
close(fd1);
 
}
