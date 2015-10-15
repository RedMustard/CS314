//
//  main.c
//  314-Lab1
//
//  Created by Travis Barnes on 10/13/15.
//  Copyright (c) 2015 Travis Barnes. All rights reserved.
//
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
int to_binary_conversion(int, char*, char*);
bool input_check(i)
int main(){
    
    char in_number[MAX_NUM+1];
    int in_base = 0;
    int out_base = 10;
//    char out_number[MAX_NUM+1];
    char possible_characters[16] = {'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'};
    
    printf("Please enter the desired starting base: ");
    scanf("%d", &in_base);
    printf("Please enter the desired ending base: ");
    scanf("%d", &out_base);
    printf("Please enter the desired number to be converted: ");
    scanf("%s", &in_number);

//    printf("%d", in_base);
//    printf("\n%d", out_base);
//    printf("\n%s", in_number);
//    printf("\n%c", in_number[0]); // formatting to print specific index
    
//    total = pow(in_base, 0);
//    printf("%d", total);
//    int q = 0;

    printf("%d",to_binary_conversion(in_base, in_number, possible_characters));
}


int to_binary_conversion(int in_base, char* in_number, char* possible_characters) {
    int total = 0;
    int p = (strlen(in_number)-1);
    
    for (int q = 0; q < strlen(in_number); q++) {
        for (int i = 0; i < in_base; i++) {
            if (in_number[q] == possible_characters[i]) {
                total += i*(pow(in_base, p));
                p--;
            }
        }
    }
    return total;
}

////////////////////
/////////// TODO: Function to check for invalid input
////////////////////
    
    ///// if in_number == possible_characters in range (11-16)
    /////   int n2 = value of hex letter
    ////
    /////
    //////
    //////
//    int n = atoi(&in_number);
//    printf("%d", n);

//////////////////
//////////  Converts Bases 2-10 to Base 10
//    while(n)
//    {
//        
//        printf("%d\n", n %10);
//        total += ((n%10)*pow(in_base, p));
//        n /= 10;
//        p++;
//    }
//////////
//////////////////
    
//    printf("\n%d", total);
//    printf("%d", total);
//    for (int i = 0; i < strlen(in_number); i++) {
//        printf("%d ", i);
//        printf("%c\n", in_number[i]+1); // prints +1 to in_num[i]
//        int n = atoi(&in_number[i]);
//        printf("%d", n);
//        printf("%d ", n);
    
/////////////
//////  Correctly calculates exponents
//        total = (pow(in_base, p));
//        printf("%d ", total);
//        p++;
//    }
//////
////////////

