#include "Arrayops.h"
void Insert_sort(int a[], int n) {
	//Insert sort/插入排序
	//时间复杂度：O(n^2)
	//特点：原地排序，对于部分有序小规模数组很有效，并且是稳定排序。
	for (int i=1; i < n; i++) {
		int j = 0;
		for (j = i-1; j > 0 && a[j] > a[i]; j--);
		if(a[ j ]>a[i]){
			insert(a, i, j);
		}
		else {
			insert(a, i, j + 1);
		}
	}
}