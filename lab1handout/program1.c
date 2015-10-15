/*
 * CIS 314 Fall 2015 Lab 1
 * Assigned project
 * 
 * This program converts a x base to y base converter [less than 16]. 
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

#define MAX_NUM 16
#define MAX_DECIMAL 2147483647 //for int

// Implement the rest of the program

int main(){

	char in_number[MAX_NUM+1];
	int in_base = 0;
	int out_base = 0;
	char out_number[MAX_NUM+1];
    
    String Conversion(int M, int N)	// return string, accept two integers
    	{
        	    Stack stack = new Stack();	// create a stack
        	    while (M >= N)	// now the repetitive loop is clearly seen
            	    {
                	        stack.push(M mod N);	// store a digit
                	        M = M/N;	// find new M
                	    }
        	    // now it's time to collect the digits together
        	    String str = new String(""+M);	// create a string with a single digit M
        	    while (stack.NotEmpty())
            	        str = str+stack.pop()	// get from the stack next digit
            	    return str;


	return 0;
}
