#include "Sort.h"
#include "Arrayops.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_LEN 1000000


int main(){
	srand(time(NULL));
	Elemtype a[MAX_LEN];
	int index = 0;
	for (int i = 0; i < MAX_LEN; i++) {
		a[i] = rand();//Ϊʲôһ����ϴ���㷨�ᵼ�´�����ֶ���ǰ�棿����Ϊrand����һ��0-0x7fff����������������32767��һ��������˺�����Ľϴ�����ֱ�����ǰ32767�����ڡ�
		//index = rand() % (i+1);
		//exc(&a[index],&a[i]);
	}
	//print_array(a,MAX_LEN);
	Sortcompare(Quick_sort,Merge_sort_tb,a,MAX_LEN);
	//Bubble_sort(a, MAX_LEN);
	//Selection_sort(a, MAX_LEN);
	//Insert_sort(a, MAX_LEN);
	//Shellsort(a, MAX_LEN);
	//Merge_sort_bt(a,MAX_LEN);
	//clock_t start, end;
	//start = clock();
	//Merge_sort_bt(a, MAX_LEN);
	//Quick_sort(a, MAX_LEN);
	//end = clock();
	//printf("��ʱ %.6f s",(double)(end-start)/CLK_TCK);
	//Quick_sort(a,MAX_LEN);
	printf("\n");
	//print_array(a, MAX_LEN);

	return 0;
}