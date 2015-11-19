//Dynamic Declare and resize of string
char* str = malloc(size*sizeof(char));
if (str == NULL)
 return NULL; // out of memory
str = realloc(str, size*sizeof(char));
c = getchar();

//Return a string you declared dynamicaly 
//use as an array
char* getString(void)
str[i++] = c;
return str;
char *str = getString(); //in main
printf("yourString(%s)", str );

//Set int array to zero//Replace bool array in java
int count[256];
memset(count,0,256*sizeof(int));

//Compile code
gcc myfile.c -o main.out  
./main.out

//Compile header file  
// .h file
#ifndef WHATEVER_H_INCLUDED
#define WHATEVER_H_INCLUDED
int f(int a);
#endif
// .c file
#include "whatever.h"
int f(int a) { return a + 1; }


