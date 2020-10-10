#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include "Arrayops.h"

void Sortcompare(void *ptr1(int a[], int n), void *ptr2(int a[], int n), int a[],int n) {
	int* b = (int*)malloc(n * sizeof(int));
	//int* c = (int*)malloc(n * sizeof(int));
	clock_t start, end;
	double t1, t2;
	for (int i = 0; i < n; i++) {
		b[i] = a[i];
	}
	start = clock();
	ptr1(b,n);
	end = clock();
	t1 = (double)(end-start) / CLK_TCK;
	free(b);

	b = (int*)malloc(n * sizeof(int));
	for (int i = 0; i < n; i++) {
		b[i] = a[i];
	}
	start = clock();
	ptr2(b, n);
	end = clock();
	t2 = (double)(end-start) / CLK_TCK;
	//print_array(b, n);
	printf("ÅÅÐòËã·¨1ºÄÊ± %.6f s\n",t1);
	printf("ÅÅÐòËã·¨2ºÄÊ± %.6f s\n",t2);

	free(b);
}