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
int to_base10(int, char*, char*);
void from_base10(int, char*, char*);
//bool input_check(i)
int main(){
    
    char in_number[MAX_NUM+1];
    int in_base = 0;
    int out_base = 0;
    char possible_characters[16] = {'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'};
    
//    printf("Please enter the desired starting base: ");
//    scanf("%d", &in_base);
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
//    if (out_base == 10) {
//      printf("Converted value: %d",to_base10(in_base, in_number, possible_characters));
//    } else {
        from_base10(out_base, in_number, possible_characters);
//    }
}

int to_base10(int in_base, char* in_number, char* possible_characters) {
    int total = 0;
    long p = (strlen(in_number)-1);
    
    for (int q = 0; q < strlen(in_number); q++) {
        for (int i = 0; i < in_base; i++) {
            if (in_number[q] == possible_characters[i]) {
                total += i*(pow(in_base, p));
                p--;
            } else {
                printf("An invalid character has been entered.");
            }
        }
    }
    return total;
}

void from_base10(int out_base, char* in_number, char* possible_characters) {
    char out_number[17] = {'0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0'};
    int n = atoi(in_number);
    int remainder = 0;
    long i = strlen(out_number);
    int m = 0;
    
    out_number[i] = '\0';
  
//    for (n; n != 0; n = n/out_base) {
//        remainder = n%out_base;
//        out_number[i] = possible_characters[remainder];
//        i--;
//    }
    
    do {
        remainder = n%out_base;
        n = n/out_base;
        out_number[i--] = possible_characters[remainder];
//        i--;
//        printf("%d", remainder);
    } while(n != 0);
    
    while (out_number[m] == '0') {
        m++;
    }
    while (m <= 17) {
        printf("%c", out_number[m]);
        m++;
    }

}

    
//    function to change your decimal -> binary
    // void DecimalToBinary(int decimal, char * (binaryString+14)) --- binaryString+14 will point to just before null '\0'. Further iteration will subtract (--binaryString) 1 place. Ultimately placing binary from right to left
    //      if decimal == 0 return;
    //      quotient = decimal/2
    //      remainder = decimal%2
    //      *binary = remainder
    //      DecimalToBinary(quotient, --binaryString)



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

