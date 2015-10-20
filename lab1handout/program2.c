//
//  main.c
//  314-Lab1b
//
//  Created by Travis Barnes on 10/19/15.
//  Copyright (c) 2015 Travis Barnes. All rights reserved.
//
/*
 * CIS 314 Fall 2015 Lab 1
 * Assigned project
 *
 * This program reads a sorted array from a file and finds a requested number
 *    using recursive or iterative binary search. The array is read from a file
 *    defined by FILE_NAME, which should be written as the number of elements
 *    followed by the elements themselses. each number can be deliniated with
 *    any whitepace character. Also, the maximum size of the array is defined
 *    as MAX_SIZE.
 *
 * NOTE: The array must be sorted!!
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 150
#define FILE_NAME "array.dat" //must include quotes


void iterative_binary(int, int, int *);
//void recursive_binary(int, int, int *);
int main(void) {
    
    FILE *in_file;
    in_file = fopen("array.dat", "r");
    int array[MAX_SIZE];
    int size;
    int value;
    char in_file_name[] = FILE_NAME;
    
    if (in_file == NULL) {
        printf("Error Reading File\n");
        exit (0);
    }
    
    for (int i=0; i < 101; i++) {
        fscanf(in_file, "%d", &array[i-1]);
    }
    
    size = array[-1];
    
    printf("Please enter the number you would like to search for: ");
    scanf("%d", &value);
    
    iterative_binary(size, value, array);
    
    return 0;
}


void iterative_binary(int size, int value, int * array) {
    int max = size;
    int min = array[0];
    int delta;
    clock_t t1, t2;

    t1 = clock();
    
    while (min <= max) {
        int mid = (max+min)/2;

        if (array[mid] == value) {
            t2 = clock();
            delta = t2 - t1;
            printf("The number you are searching for has been found at index: %d\n", mid);
            printf("It took %Lfms to find your number.", (long double) delta);
            exit(0);
            
        } else if (array[mid] < value) {
            min = mid+1;
            
        } else {
            max = mid-1;
        }
    }
    printf("Your number could not be found.");
}

//void recursive_binary(int size, int value, int * array) {
//    int max = size;
//    int min = array[1];
//    int delta;
//    clock_t t1, t2;
//    
//    t1 = clock();
//    
//    if (max < min) {
//        printf("Your number could not be found.");
//    } else {
//        mid = (max+min)/2;
//        
//        if (array[mid] > value) {
//            recursive_binary(<#int size#>, <#int value#>, <#int *array#>)
//        }
//    }
//}


//////////// RECURSIVE /////////////
//int binary_search(int A[], int key, int imin, int imax)
//{
//    // test if array is empty
//    if (imax < imin)
//        // set is empty, so return value showing not found
//        return KEY_NOT_FOUND;
//    else
//    {
//        // calculate midpoint to cut set in half
//        int imid = midpoint(imin, imax);
//        
//        // three-way comparison
//        if (A[imid] > key)
//            // key is in lower subset
//            return binary_search(A, key, imin, imid - 1);
//        else if (A[imid] < key)
//            // key is in upper subset
//            return binary_search(A, key, imid + 1, imax);
//        else
//            // key has been found
//            return imid;
//    }
//}
//////////////////////////////



////////// TIMING //////////
//int delta;
//clock_t t1, t2;
//t1 = clock();
//// CODE HERE
//t2 = clock();
//delta = t2 - t1;
////////////////////////////