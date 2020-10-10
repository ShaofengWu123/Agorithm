#include "Arrayops.h"
void Bubble_sort(int a[], int n) {
	//Bubble sort/冒泡排序
	//时间复杂度：O(n^2)
	//特点：原地排序，稳定性取决于比较的时候含不含等于。
	for (int k=0;k<n-1;k++) {
		for (int i = 0; i < n - 1 - k; i++) {
			if (a[i] > a[i + 1]) { exc(&a[i],&a[i+1]); }
		}
	}
}
