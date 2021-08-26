#The Shell Project.

##Synopsis:

This is simple UNIX command interpreter that reads commands from standard input and executes them, simulating the behavior of the sh (/bin/sh) command interpreter (shell).
The program was written in C and is part of the low-level programming project at Holberton School.

##Description:

The shell can execute command line arguments read from the standard input. It reads line by line from a file or the terminal line. It then interprets the lines and executes it if the line is a valid command.

##Use:

The hsh was coded on an Ubuntu 20.04 LTS machine.
```
The code is compiled with gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh command.
```
Once compiled, to start the program, run:
```
./hsh
```
To exit the program, run:
```
exit
```
##Built-Ins:
