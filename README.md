
# SS-1
Assignment one for system software.

Objective:
The purpose of this assignment is to write a C-program, using a function that will parse a string into tokens (or words), similar 
to what the shell is required to do.

Functionality:
For this assignment, you are to write a function with the following prototype:
int makearg(char *s, char ***args); // or
int makearg(char s[], char **args[]);
(Yes, that is the correct prototype, please don’t change it). The function should accept a (C-type) string and a pointer to a 
pointer to char (or, if you prefer, a pointer to an array of pointers to char) (i.e., a pointer to the same type as "argv" in a
C program), and should return the pointer defined to point to an array pointing to the separate tokens on the command line, as 
well as the number of tokens found as the function return. If some problem occured during the operation of the function, 


the value returned should be -1.
For example, if you were to call the function using the following code,
char **args, str[] = "ls -l file";
int argc;
argc = makearg(str, &args);


Side-Note:
The important part of this exercise is the function you write. However, for consistency in grading, your main program should be 
written to input a line, call the function, then printout the number of arguments found, and finally, print out the arguments, one 
per line. Note that, as in the example above, the value of the pointer argument is undefined when it is passed to the "makearg" 
function. "makearg" must allocate any necessary dynamic memory, necessary for use by the program.
