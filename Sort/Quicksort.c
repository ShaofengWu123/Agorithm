#include "Arrayops.h"
#include "Sort.h"

int counter1=0;
void Quick_sort(Elemtype a[],int n) {
	//Quick sort/快速排序
	//时间复杂度:O(nlogn)
	//特点：原地排序，不是稳定排序(比较时固定不取等号，防止对于只有若干种主键的序列，当分割到子数组只有两种主键的时候，继续分割的子数组必有一个为空，算法运行时间变成平方级别)，适合随机排列序列，经过改进（三向切分）可以用于有大量重复主键的序列。
	//平均比较次数1.39nlogn，平均交换次数1/6*平均比较次数。比较次数大于归并排序(1/2nlogn~nlogn)但是移动数据次数小于归并排序(每层复制n次，排回原数组n次)，因此一般快于归并。
	//shuffle(a, n);//打乱数组，防止出现糟糕的分组，即相等主键在一组里，导致时间变成平方级别
	exc(&a[n - 1], &a[findmax(a, n)]);//数组最大的元素放到最后作为“哨兵”
	quick_sort(a, 0, n - 1);
	printf("快速排序比较次数:%d\n",counter1);
}

//void quick_sort(Elemtype a[], int min, int max) {
//	if (max <= min) { ; }
//	else {
//		int i=partition(a,min,max);
//		quick_sort(a,min,i==max? max-1:i);//每次分割都把分割元素包含进了子数组里作为哨兵，会导致比较次数变多，但是内循环判断i，j是否越界不再需要，判断次数变少
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

//三向快速排序
void Quick_sort_3way(Elemtype a[], int n) {
	partitionandsort_3way(a,0,n-1);
}


void partitionandsort_3way(Elemtype a[], int min, int max) {
	if (max <= min) { ; }
	else
	{
		int j = min; int i = min + 1; int k = max;
		int flag = 0;
		Elemtype v = a[min];
		while (i<=k) {
			flag = a[i] > v ? 1 : (a[i]==v? 0:-1);
			if (flag == 1) { exc(&a[i],&a[k--]); }
			else if (flag == -1) { exc(&a[j++],a[i++]); }
			else { i++; }
		}
		partitionandsort_3way(a,min,j-1);
		partitionandsort_3way(a,i,max);
	}
}
