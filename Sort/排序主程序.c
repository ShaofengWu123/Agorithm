#include "Sort.h"
#include "Arrayops.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_LEN 250000
#define Elemtype int

int main(){
	srand(time(NULL));
	Elemtype a[MAX_LEN];
	for (int i = 0; i < MAX_LEN; i++) {
		a[i] = (rand() % 101);
	}
	//print_array(a,MAX_LEN);
	Sortcompare(Merge_sort_bt,Shell_sort,a,MAX_LEN);
	//Bubble_sort(a, MAX_LEN);
	//Selection_sort(a, MAX_LEN);
	//Insert_sort(a, MAX_LEN);
	//Shellsort(a, MAX_LEN);
	//Merge_sort_bt(a,MAX_LEN);
	//Merge_sort_bt(a, MAX_LEN);
	//print_array(a, MAX_LEN);
	return 0;
}