#include "Arrayops.h"
void Selection_sort(int a[], int n) {
	//Selection sort/选择排序
	//时间复杂度:O(n^2)
	//特点：原地排序，是不是稳定排序取决于比较的时候含不含等号。无法发现原本有序的序列。
	int min = 0;
	for (int i = 0; i < n-1; i++) {
		min = i;
		for (int j = i + 1; j < n; j++) {
			min = (a[j] < a[min] ? j : min);
		}
		exc(&a[i],&a[min]);
	}
}