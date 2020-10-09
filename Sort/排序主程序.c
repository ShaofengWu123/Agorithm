#include "Sort.h"
#include "Arrayops.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_LEN 250000


int main(){
	srand(time(NULL));
	Elemtype a[MAX_LEN];
	int index = 0;
	for (int i = 0; i < MAX_LEN; i++) {
		a[i] = i;
		index = rand() % (i + 1);
		exc(&a[index],&a[i]);
	}
	//print_array(a,MAX_LEN);
	Sortcompare(Quick_sort,Merge_sort_tb,a,MAX_LEN);
	//Bubble_sort(a, MAX_LEN);
	//Selection_sort(a, MAX_LEN);
	//Insert_sort(a, MAX_LEN);
	//Shellsort(a, MAX_LEN);
	//Merge_sort_bt(a,MAX_LEN);
	//Merge_sort_bt(a, MAX_LEN);
	//Quick_sort(a,MAX_LEN);
	//print_array(a, MAX_LEN);
	return 0;
}