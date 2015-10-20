//  CIS 314 Fall 2015 Lab 1
//
//  This program converts a x base to y base converter [Bases 2-16].
//
//  Created by Travis Barnes on 10/13/15.
//  Copyright (c) 2015 Travis Barnes. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
#include <math.h>

#define MAX_NUM 16
#define MAX_DECIMAL 2147483647

int to_base10(int, char*, char*); // Convert from bases 2-16 to base 10
void from_base10(int, char*, char*); // Convert from base 10 to bases 2-16
bool input_validation(int, int, char*, char*); // Validate whether user has entered correct inputs

int main(){
    char in_number[MAX_NUM+1];
    int in_base = 0;
    int out_base = 0;
    char possible_characters[16] = {'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'};
    
    // Accept user input
    printf("Please enter the desired starting base: ");
    scanf("%d", &in_base);
    printf("Please enter the desired ending base: ");
    scanf("%d", &out_base);
    printf("Please enter the desired number to be converted: ");
    scanf("%s", * &in_number);
    
    // Validate input
    if (input_validation(in_base, out_base, in_number, possible_characters) == true) {
        // If input is error-free, choose the correct conversion method
        if (out_base == 10) {
            printf("Converted value: %d",to_base10(in_base, in_number, possible_characters));
        } else {
            from_base10(out_base, in_number, possible_characters);
        }
    } else {
        printf("You have entered invalid input. Please try again.");
    }
}

int to_base10(int in_base, char* in_number, char* possible_characters) {
    int total = 0;
    long p = (strlen(in_number)-1); // For use as exponent
    
    // For every character in in_number, determine its location i in possible_characters and
    //  compute total
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

void from_base10(int out_base, char* in_number, char* possible_characters) {
    char out_number[17] = {'0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0'};
    int n = atoi(in_number); // Convert in_number to int for calculation
    int remainder = 0;
    long i = 17; // Start the counter at the end of  out_number
    int m = 0;
    
    out_number[i] = '\0'; // Make sure the char array has a terminator at the end
    
    // While n doesn't equal 0, calculate the remainder and add to  out_number  array in reverse order
    do {
        remainder = n%out_base;
        n = n/out_base;
        out_number[i--] = possible_characters[remainder];
    } while(n != 0);
    
    // Disregard beginning 'empty' ('0') characters when printing converted number
    printf("Converted value: ");
    while (out_number[m] == '0') {
        m++;
    }
    while (m <= 17) {
        printf("%c", out_number[m]);
        m++;
    }
}

bool input_validation(int in_base, int out_base, char* in_number, char* possible_characters) {
    int n = atoi(in_number);
    
    // If  in_base  or  out_base  are not bases 2-16, return false.
    if (1 >= in_base || in_base > 16 || 1 >= out_base || out_base > 16) {
        return false;
    }
    
    // Check for  in_number  to be less than  MAX_DECIMAL and greater than 0.
    if (n > MAX_DECIMAL || n < 0) {
        return false;
    }
    
    // Check for  in_number  to be 16 digits or less.
    if (strlen(in_number) > 16) {
        return false;
    }
    
    // For every character in in_number, determine if it is located in possible_characters and
    //  return true if so. Otherwise, return false.
    for (int q = 0; q < strlen(in_number); q++) {
        for (int i = 0; i < in_base; i++) {
            if (in_number[q] == possible_characters[i]) {
                return true;            }
        }
    }
    return false;
}