#include <stdio.h>
#include <stdlib.h>
#include "Arrayops.h"

int counter2 = 0;
void Merge(int a[], int temp[],int min, int mid, int max) {
	for (int i = min; i <= max; i++) {
		temp[i] = a[i];
	}
	int j = min; int k = mid + 1;
	for (int i = min; i <= max; i++) {
		if (j > mid)      { a[i] = temp[k]; k++; }//注意if...else if...语句的顺序，要先判断j、k有没有越界
		else if (k > max) { a[i] = temp[j]; j++; }
		else if (temp[j] <= temp[k]) { counter2++; a[i] = temp[j]; j++; }
		else if (temp[j]  > temp[k]) { counter2++; a[i] = temp[k]; k++; }//这里不取等号是为了保证排序的稳定性，相等的元素原本在后面的不会到前面
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
	//自顶向下的归并排序
	//时间复杂度:O(nlgn)
	//特点：渐进最优的基于比较排序的算法。不是原地排序，所使用的额外空间与n成正比，是不是稳定排序取决于比较元素的时候是否取等号。
	//几种优化方式：1.小子数组用选择排序 2.判断a[mid]<a[mid+1]跳过merge()方法 3.每次归并交换辅助数组与原数组的角色，
	//              不把元素固定复制到辅助数组，而是把元素从A/B数组排序到B/A数组里面
	int *temp = (int *)malloc(n*sizeof(int));
	Merge_sort(a,temp,0, n-1);
	printf("归并排序比较次数:%d\n", counter2);
	free(temp);
}

void Merge_sort_bt(int a[], int n) {
	int* temp = (int*)malloc(n * sizeof(int));
	int max = 0;
	for (int i=1; i < n; i += i) {
		for (int j=0; j < n; j += 2*i) {
			max = (j + 2*i - 1) > (n - 1) ? (n - 1) : (j + 2*i - 1);
			Merge(a, temp, j, j+i-1, max);
		}
	}
}