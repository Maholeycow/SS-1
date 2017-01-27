/* Author: Patrick VanVorce
 * Class: CS270
 * Instructor: Ananth
 * Assignment: 1
 * Date&Time due: 1/27/2017 @ 11:59 p.m.
 * Description: Write a C program, using a function that will parse a string into 
 *              tokens, similar to what the shell is required to do.
 */

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int makearg(char s[], char **args[]);
void append(char *h, char c); // adds a letter to whatever string given


int main(void)
{
  char **args, str[] = "ls -l file";
  int argc;
  argc = makearg(str, &args);

  printf("Number of arguments found: %d\n", argc);

  int i = 0;
  /*if(args[i]!=NULL){
   for(i; i<argc; i++)
    {
      printf("These are the arguments found: /n");
      printf("%s\n", args[i]);
    }
  }
  */
  //  printf("Did it change in memory: %s\n", *args[0]);
  
  printf("Size of args in main: %lu\n\n", sizeof(**args));

  free (args);
    
  return 0;
}

int makearg(char *s, char **args[])
{
  char *strPtrOne, *strPtrTwo; //pointers to the string
  strPtrOne = s;
  int space = 0;
  
  for(space; *strPtrOne != '\0'; strPtrOne++){
    if(*strPtrOne!=' ')
      continue; //If we see a space, we go to the next loop
    space++; //Keep track of how many spaces
  }

  int count = space + 1; //this sets count to the number of token
  
  getchar(); //this is to handle if the string were empty

  args = malloc(count * sizeof(char*)); // allocate the array index size
  if (NULL == args) { //This is to handle error of allocation
    fprintf(stderr, "malloc failed\n");
    return(-1);
  }

  int i = 0;
  int k = 0;
  strPtrTwo = s;
  char str[10] = "";
  while(*strPtrTwo != '\0')
    {
      if(*strPtrTwo==' ')
	{
	  printf("stringInStr: %s\n", str);
	  printf("valueOfK: %d\n", k);
	  //args[k] = malloc(strlen(str) * sizeof*args[k]);
	  printf("stringLength: %lu\n", strlen(str));
	  args[k] = malloc(strlen(str)*sizeof(char*));
	  *args[k] = str;  
	  printf("stringInArgs: %s\n", *args[k]);
	  memset(str, 0, strlen(str)); //this empties the string
	  printf("Did string reset: %s\n\n", str);
	  k++;
    	} else {
	append(str, *strPtrTwo);
	printf("charByChar: %s\n", str);}
      strPtrTwo++;
    }
  printf("lastValueOfStr: %s\n", str);
  printf("valueOfK: %d\n", k);
  printf("stringLength: %lu\n", strlen(str));
  args[k] = malloc(strlen(str) * sizeof*args[k]);
  printf("whereIsTheError: %s\n", *args[k]);
  //strcat(args[k], str);
  *args[k] = str;
  printf("isTheErrorHere: %s\n", *args[k]);
  printf("index0: %s\n", *args[0]);
  printf("index1: %s\n", *args[1]);
  printf("index2: %s\n", *args[2]);
  printf("%lu\n", sizeof(**args));
  //printf("%s\n", **args);

  for(int p = 0; p<count; p++)
    {
      printf("Arguments: %s\n", *args[p]);
    }

  return count;
  //return *args;
}

void append(char h[], char c)
{
  int len = strlen(h);
  h[len] = c;
  h[len+1] = '\0';
}

 
