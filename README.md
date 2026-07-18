# Linux Utilities Implementation

## Description
This repository contains custom, low-level implementations of standard Unix command-line utilities written in C. These programs directly utilize Linux system calls (such as `open`, `read`, `write`, and `rename`) to handle memory buffering and file I/O operations. Strict error checking is implemented on all system call return values to ensure safe and robust execution.

The following utilities are included in this project:
* **`echo`**: Prints command-line arguments to the standard output.
* **`cp`**: Copies the contents of a source file to a destination file using an efficient 4KB read/write buffer loop to manage memory safely.
* **`mv`**: Moves or renames a file by utilizing atomic directory table updates.
* **`pwd`**: Retrieves and prints the absolute path of the current working directory.

## Compilation Commands
The utilities are compiled using the GCC compiler with standard warning flags to ensure clean, error-free code. Run the following commands to generate the executables:

```bash
gcc -Wall -Werror -o echo echo.c
gcc -Wall -Werror -o cp cp.c
gcc -Wall -Werror -o mv mv.c
gcc -Wall -Werror -o pwd pwd.c

## Examples of output:
$cd ~/Linux_utilities_implementation$ ./pwd
/home/user/Linux_utilities_implementation


$ ./echo Hello World
Hello World


$ echo "Test data" > source.txt
$ ./cp source.txt dest.txt
$ cat dest.txt
Test data



$ touch temp.txt
$ ./mv temp.txt new_name.txt
$ ls -a
.  ..  cp  cp.c  echo  echo.c  mv  mv.c  new_name.txt  pwd  pwd.c
