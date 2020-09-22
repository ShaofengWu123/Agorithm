#include <stdio.h>
//打印数组
void print_array(int a[], int n) {
	for (int i = 0; i < n; i++) {
		printf("%d ", a[i]);
	}
	printf("\n");
}

//交换两个元素
void exc(int* a, int* b) {
	int temp = 0;
	temp = *a;
	*a = *b;
	*b = temp;
}

//把索引i元素插到索引j处
void insert(int a[], int i, int j) {
	int temp = a[ i ];
	for (int k = i; k > j; k--) {
		a[k] = a[k - 1];
	}
	a[ j ] = temp;
}