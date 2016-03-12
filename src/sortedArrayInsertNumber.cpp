/*
OVERVIEW: Given a sorted array, insert a given number into the array at appropriate position.
			E.g.: Arr = [2, 4, 6], num = 5 final Arr = [2, 4, 5, 6]. 5 is inserted at 2nd index.

INPUTS: Integer	Array pointer, length of the array, number to be inserted.

OUTPUT: Array pointer after inserting number.

ERROR CASES: Return NULL for invalid inputs.

NOTES: Use realloc to allocate memory.
*/

#include <stdio.h>
#include <malloc.h>

int * sortedArrayInsertNumber(int *Arr, int len, int num)
{
	int i = 0, p = 0, *k,flag=0;
	
	k = (int *)malloc((len + 1)*sizeof(int));
	if (Arr == NULL || len<0 ){
		return NULL;
	}
		if (num < Arr[0]){
			flag = 1;
			k[0] = num;
			p = i + 1;
			while (p != len + 1 && p <= len + 1){
				k[p] = Arr[p - 1];
				p++;
			}
			Arr = (int *)realloc(Arr, (len + 1)*sizeof(int));
			len++;
			for (i = 0; i < len + 1; i++){
				Arr[i] = k[i];
			}
	}
		if (flag==1)
		return Arr;
		if (num>Arr[len - 1]){
			flag = 2;
			p = i + 1;
			int q = p;
			while (q != 0 && q > 0)
			{
				k[q - 1] = Arr[q - 1];
				q--;
			}
			k[len] = num;
			Arr = (int *)realloc(Arr, (len + 1)*sizeof(int));
			len++;
			for (i = 0; i < len + 1; i++){
				Arr[i] = k[i];
			}
	}
		if (flag == 2)
			return Arr;
	for (i = 0; i<len;){
		if (num > Arr[i] && num < Arr[i + 1]){
			flag = 3;
			p = i + 1;
			int q = p;
			while (q != 0 && q>0)
			{
				k[q - 1] = Arr[q - 1];
				q--;
			}
			while (p == i + 1){
				k[p] = num;
				p++;
			}
			while (p != len + 1 && p <= len + 1){
				k[p] = Arr[p - 1];

				p++;
			}
			Arr = (int *)realloc(Arr, (len + 1)*sizeof(int));
			len++;
			for (i = 0; i<len + 1; i++){
				Arr[i] = k[i];
			}
		}
		else if (num>Arr[i] && num>Arr[i + 1]){
			i++;
		}
	}
	if (flag==3)
	return Arr;
}