#include <stdio.h>
#include <stdlib.h>
#include "Sort.h"
#include <time.h>
//��ӡ����
void print_array(int a[], int n) {
	for (int i = 0; i < n; i++) {
		printf("%d ", a[i]);
	}
	printf("\n");
}

//��������Ԫ��
void exc(Elemtype* a, Elemtype* b) {
	Elemtype temp = 0;
	temp = *a;
	*a = *b;
	*b = temp;
}

//�Ƚ�����Ԫ��



//������iԪ�ز嵽����j��
void insert(int a[], int i, int j) {
	int temp = a[ i ];
	for (int k = i; k > j; k--) {
		a[k] = a[k - 1];
	}
	a[ j ] = temp;
}

//�ҵ����Ԫ��(������)
int findmax(Elemtype a[], int n) {
	int index = 0;
	for (int i = 0; i < n; i++) {
		index = a[index] > a[i] ? index : i;
	}
	return index;
}
//����ϴ��
void shuffle(Elemtype a[], int n) {
	srand(time(NULL));
	int index;
	for (int i = 0; i < n; i++) {
		index = rand() % (i + 1);
		exc(&a[i], &a[index]);
	}
}