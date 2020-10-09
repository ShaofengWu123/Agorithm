#include "Arrayops.h"
#include "Sort.h"

void Quick_sort(Elemtype a[],int n) {
	//shuffle(a, n);//打乱数组，防止出现糟糕的分组
	exc(&a[n - 1], &a[findmax(a, n)]);//数组最大的元素放到最后作为“哨兵”
	quick_sort(a, 0, n - 1);
}

void quick_sort(Elemtype a[], int min, int max) {
	if (max <= min) { ; }
	else {
		int i=partition(a,min,max);
		quick_sort(a,min,i==max? max-1:i);
		quick_sort(a,i==min? min+1:i,max);
	}
}

int partition(Elemtype a[],int min,int max) {
	int i = min; int j = max+1;
	Elemtype v = a[min];
	while (1) {
		while (a[++i] < v) { ; }
		while (a[--j] > v) { ; }
		if (i >= j) { break; }
		exc(&a[i],&a[j]);
	}
	exc(&a[min], &a[j]);
	return j;
}