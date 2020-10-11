#include "Arrayops.h"
#include "Sort.h"

int counter1=0;
void Quick_sort(Elemtype a[],int n) {
	//Quick sort/��������
	//ʱ�临�Ӷ�:O(nlogn)
	//�ص㣺ԭ�����򣬲����ȶ�����(�Ƚ�ʱ�̶���ȡ�Ⱥţ���ֹ����ֻ�����������������У����ָ������ֻ������������ʱ�򣬼����ָ�����������һ��Ϊ�գ��㷨����ʱ����ƽ������)���ʺ�����������У������Ľ��������з֣����������д����ظ����������С�
	//ƽ���Ƚϴ���1.39nlogn��ƽ����������1/6*ƽ���Ƚϴ������Ƚϴ������ڹ鲢����(1/2nlogn~nlogn)�����ƶ����ݴ���С�ڹ鲢����(ÿ�㸴��n�Σ��Ż�ԭ����n��)�����һ����ڹ鲢��
	//shuffle(a, n);//�������飬��ֹ�������ķ��飬�����������һ�������ʱ����ƽ������
	exc(&a[n - 1], &a[findmax(a, n)]);//��������Ԫ�طŵ������Ϊ���ڱ���
	quick_sort(a, 0, n - 1);
	printf("��������Ƚϴ���:%d\n",counter1);
}

//void quick_sort(Elemtype a[], int min, int max) {
//	if (max <= min) { ; }
//	else {
//		int i=partition(a,min,max);
//		quick_sort(a,min,i==max? max-1:i);//ÿ�ηָ�ѷָ�Ԫ�ذ�����������������Ϊ�ڱ����ᵼ�±Ƚϴ�����࣬������ѭ���ж�i��j�Ƿ�Խ�粻����Ҫ���жϴ�������
//		quick_sort(a,i==min? min+1:i,max);
//	}
//}
//
//int partition(Elemtype a[], int min, int max) {
//	int i = min; int j = max + 1; int temp = 0;
//	Elemtype v = a[min];
//	while (1) {
//		while (a[++i] < v) { counter1++; }//
//		counter1++;
//		while (a[--j] > v) { counter1++; }
//		counter1++;
//		if (i >= j) { break; }
//		/*temp = a[i];
//		a[i] = a[j];
//		a[j] = temp;*/
//		exc(&a[i], &a[j]);
//	}
//	/*temp = a[min];
//	a[min] = a[j];
//	a[j] = temp;*/
//	exc(&a[min], &a[j]);
//	return j;
//}

void quick_sort(Elemtype a[], int min, int max) {
	if (max <= min) { ; }
	else {
		int i=partition(a,min,max);
		quick_sort(a,min,i-1);
		quick_sort(a,i+1,max);
	}
}

int partition(Elemtype a[],int min,int max) {
	int i = min; int j = max + 1; int temp = 0;
	Elemtype v = a[min];
	while (1) {
		while (a[++i] < v) { counter1++; if (i == max) break; }
		counter1++;
		while (a[--j] > v) { counter1++; if (j == min) break; }
		counter1++;
		if (i >= j) { break; }
		/*temp = a[i];
		a[i] = a[j];
		a[j] = temp;*/
		exc(&a[i],&a[j]);
	}
	/*temp = a[min];
	a[min] = a[j];
	a[j] = temp;*/
	exc(&a[min], &a[j]);
	return j;
}