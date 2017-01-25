/* Author: Patrick VanVorce
 * Class: CS270
 * Instructor: Ananth
 * Assignment: 1
 * Date&Time due: 1/27/2017 @ 11:59 p.m.
 * Description: Write a C program, using a function that will parse a string into 
 *              tokens, similar to what the shell is required to do.
 */

#include<stdio.h>
//#include<conio.h>

int makearg(char s[], char **args[]); //accepts a string, and a pointer to a pointer to char

int main(void)
{
  char **args, str[] = "ls -l file";
  int argc;
  argc = makearg(str, &args);

  printf("Number of arguments found: %d\n", argc);

  /*  for(int i=1; i<argc; i++)
    {
      printf("These are the arguments found: /n");
      printf("%s\n", **args[i]);
    }
  */
  return 0;
}

int makearg(char s[], char **args[])
{
  char *q; //pointer to the string so I can find out how many tokens
  q = s;
  int space = 0;
  int i = 0;

  for(space; *q; q++){
    if(*q!=' ')
      continue;
    space++;
  }

  int count = space + 1; //this sets count to the number of token

  getchar(); //this is to handle if the string were empty

  args = (
  args[0] = count;


  
  for(i; i < count; i++)
    {
      
    }
  
  return *args;
}
