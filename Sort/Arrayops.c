#include <stdio.h>
#include <stdlib.h>
#include "Sort.h"
#include <time.h>
//打印数组
void print_array(int a[], int n) {
	for (int i = 0; i < n; i++) {
		printf("%d ", a[i]);
	}
	printf("\n");
}

//交换两个元素
void exc(Elemtype* a, Elemtype* b) {
	Elemtype temp = 0;
	temp = *a;
	*a = *b;
	*b = temp;
}

//比较两个元素



//把索引i元素插到索引j处
void insert(int a[], int i, int j) {
	int temp = a[ i ];
	for (int k = i; k > j; k--) {
		a[k] = a[k - 1];
	}
	a[ j ] = temp;
}

//找到最大元素(的索引)
int findmax(Elemtype a[], int n) {
	int index = 0;
	for (int i = 0; i < n; i++) {
		index = a[index] > a[i] ? index : i;
	}
	return index;
}
//数组洗牌
void shuffle(Elemtype a[], int n) {
	srand(time(NULL));
	int index;
	for (int i = 0; i < n; i++) {
		index = rand() % (i + 1);
		exc(&a[i], &a[index]);
	}
}