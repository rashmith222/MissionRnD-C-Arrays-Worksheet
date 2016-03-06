/*
OVERVIEW: In a given ascending sorted array, two numbers are changed their position, please fix those two numbers.
E.g.: In [10, 40, 30, 20, 50] 20 and 40 are swapped, so final output will be [10, 20, 30, 40, 50]

INPUTS: Ascending sorted array with two positions swapped, length of the array.

OUTPUT: Update sorted array by fixing swapped numbers.

ERROR CASES: Return NULL for invalid Inputs.

NOTES:
*/

#include <stdio.h>
void * sortedArrayPositionsChange(int *Arr, int len)
{
	int temp1=0, temp2=0 ,i = 0, j = 1, k=0,l=0;
	if (len < 0 || Arr == NULL){
		return NULL;
	}
	if (Arr[i] > Arr[len - 1] && Arr[i] > Arr[i + 1]){
		Arr[i] = Arr[i] * Arr[len - 1];
		Arr[len - 1] = Arr[i] / Arr[len - 1];
		Arr[i] = Arr[i] / Arr[len - 1];
	}
	for (i = 0; i < len; i++){
		for (j = i + 1; j<len; j++){
			if (Arr[j]>Arr[i] && Arr[j] > Arr[j + 1]){
				temp1 = Arr[j];
				k = j;
				break;
			}
		}
	}
	for (k = j; k < len; k++){
		for (l = k + 1; l < len; l++){
			if (Arr[l] < Arr[k] && Arr[l] < Arr[l + 1]){
				temp2=l;
				break;
			}
		}
	}
	Arr[temp1] = Arr[temp1] + Arr[temp2];
	Arr[temp2] = Arr[temp1] - Arr[temp2];
	Arr[temp1] = Arr[temp1] - Arr[temp2];
}
