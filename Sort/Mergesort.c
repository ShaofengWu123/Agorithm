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
		if (j > mid)      { a[i] = temp[k]; k++; }//ע��if...else if...����˳��Ҫ���ж�j��k��û��Խ��
		else if (k > max) { a[i] = temp[j]; j++; }
		else if (temp[j] <= temp[k]) { counter2++; a[i] = temp[j]; j++; }
		else if (temp[j]  > temp[k]) { counter2++; a[i] = temp[k]; k++; }//���ﲻȡ�Ⱥ���Ϊ�˱�֤������ȶ��ԣ���ȵ�Ԫ��ԭ���ں���Ĳ��ᵽǰ��
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
	//�Զ����µĹ鲢����
	//ʱ�临�Ӷ�:O(nlgn)
	//�ص㣺�������ŵĻ��ڱȽ�������㷨������ԭ��������ʹ�õĶ���ռ���n�����ȣ��ǲ����ȶ�����ȡ���ڱȽ�Ԫ�ص�ʱ���Ƿ�ȡ�Ⱥš�
	//�����Ż���ʽ��1.С��������ѡ������ 2.�ж�a[mid]<a[mid+1]����merge()���� 3.ÿ�ι鲢��������������ԭ����Ľ�ɫ��
	//              ����Ԫ�ع̶����Ƶ��������飬���ǰ�Ԫ�ش�A/B��������B/A��������
	int *temp = (int *)malloc(n*sizeof(int));
	Merge_sort(a,temp,0, n-1);
	printf("�鲢����Ƚϴ���:%d\n", counter2);
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