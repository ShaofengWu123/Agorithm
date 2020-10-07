#include <stdio.h>
#include <stdlib.h>
#include "Arrayops.h"

void Merge(int a[], int temp[],int min, int mid, int max) {
	for (int i = min; i <= max; i++) {
		temp[i] = a[i];
	}
	int j = min; int k = mid + 1;
	for (int i = min; i <= max; i++) {
		if (j > mid)      { a[i] = temp[k]; k++; }//注意if...else if...语句的顺序，要先判断j、k有没有越界
		else if (k > max) { a[i] = temp[j]; j++; }
		else if (temp[j] <= temp[k])   { a[i] = temp[j]; j++; }
		else if (temp[j]  > temp[k])   { a[i] = temp[k]; k++; }//这里不取等号是为了保证排序的稳定性，相等的元素原本在后面的不会到前面
	}
}

void Merge_sort(int  a[], int temp[],int min, int max) {
	if (max <= min) { ; }
	else {
		int mid = (min + max) / 2;
		Merge_sort(a,temp,min, mid);
		Merge_sort(a,temp,mid+1, max);
		Merge(a, temp,min, mid, max);
	}
}

void Merge_sort_tb(int a[], int n) {
	int *temp = (int *)malloc(n*sizeof(int));
	Merge_sort(a,temp,0, n-1);
	free(temp);
}