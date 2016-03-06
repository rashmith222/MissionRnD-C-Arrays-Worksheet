/*
OVERVIEW:  given an array that has duplicate values remove all duplicate values.
E.g.: input: [1, 1, 2, 2, 3, 3], output [1, 2, 3]

Ex 2: [4,4,2,2,1,5] output : [4,2,1,5]

INPUTS: Integer array and length of the array .

OUTPUT: Update input array by removing duplicate values and return the final array length

ERROR CASES: Return -1 for invalid inputs.

NOTES: Don't create new array, try to change the input array.
*/

#include <stdio.h>
#include<stdlib.h>
int removeArrayDuplicates(int *Arr, int len){
	int i = 0, j = 0, counter = 0, k = 0;
	counter = len;
	if (len == 1 && Arr == NULL || len <= 0){
		return -1;
	}
	for (i = 0; i < len; i++) {
		for (j = i + 1; j < len; j++) {
			if (Arr[i] == Arr[j]) {
				int  p = j;
				for (k = j + 1; k < len; k++, p++) {
					Arr[p] = Arr[k];
				}
				len--;
				counter = len;
				j--;
			}
		}
	}
	if (counter == 0)
		return -1;
	else{
		return counter;
	}
}