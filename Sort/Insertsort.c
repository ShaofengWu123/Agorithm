#include "Arrayops.h"
void Insert_sort(int a[], int n) {
	//Insert sort/��������
	//ʱ�临�Ӷȣ�O(n^2)
	//�ص㣺ԭ�����򣬶��ڲ�������С��ģ�������Ч���������ȶ�����
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