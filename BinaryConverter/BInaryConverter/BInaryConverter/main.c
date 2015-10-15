//
//  main.c
//  BInaryConverter
//
//  Created by Travis Barnes on 10/5/15.
//  Copyright (c) 2015 Travis Barnes. All rights reserved.
//

#include <stdio.h>

int main(void) {

    int decimal = 0;
    char binaryString[16];
    printf( "Please enter binary: \n" );
    scanf("%d", &decimal ); // Store value at the address (&)
    printf("%d", decimal ); // Print value

//    printf("%d", sizeof(decimal));
    Decimal

}

void DecimalToBinary(int decimal, char * binaryString) {
    printf("%d", decimal);
}

/////////////////////////////////////
////////////////////////////////////
// int main()
//      input: decimal -- scanf
//      output: string: char binaryString[16]
//      initialize binaryString = '0' -- for loop -- memset()
//      all strings must end in null character '\0' -- binaryString[15] = '\0'
//
//
//
//
// function to change your decimal -> binary
// void DecimalToBinary(int decimal, char * (binaryString+14)) --- binaryString+14 will point to just before null '\0'. Further iteration will subtract (--binaryString) 1 place. Ultimately placing binary from right to left
//      if decimal == 0 return;
//      quotient = decimal/2
//      remainder = decimal%2
//      *binary = remainder
//      DecimalToBinary(quotient, --binaryString)