#include <stdio.h>
//��ӡ����
void print_array(int a[], int n) {
	for (int i = 0; i < n; i++) {
		printf("%d ", a[i]);
	}
	printf("\n");
}

//��������Ԫ��
void exc(int* a, int* b) {
	int temp = 0;
	temp = *a;
	*a = *b;
	*b = temp;
}

//������iԪ�ز嵽����j��
void insert(int a[], int i, int j) {
	int temp = a[ i ];
	for (int k = i; k > j; k--) {
		a[k] = a[k - 1];
	}
	a[ j ] = temp;
}