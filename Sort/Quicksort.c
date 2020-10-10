#include "Arrayops.h"
#include "Sort.h"

int counter1=0;
void Quick_sort(Elemtype a[],int n) {
	//shuffle(a, n);//打乱数组，防止出现糟糕的分组
	exc(&a[n - 1], &a[findmax(a, n)]);//数组最大的元素放到最后作为“哨兵”
	quick_sort(a, 0, n - 1);
	printf("快速排序比较次数:%d\n",counter1);
}

//void quick_sort(Elemtype a[], int min, int max) {
//	if (max <= min) { ; }
//	else {
//		int i=partition(a,min,max);
//		quick_sort(a,min,i==max? max-1:i);
//		quick_sort(a,i==min? min+1:i,max);
//	}
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