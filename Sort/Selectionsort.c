#include "Arrayops.h"
void Selection_sort(int a[], int n) {
	//Selection sort/—°‘Ò≈≈–Ú
	int min = 0;
	for (int i = 0; i < n-1; i++) {
		min = i;
		for (int j = i + 1; j < n; j++) {
			min = (a[j] < a[min] ? j : min);
		}
		exc(&a[i],&a[min]);
	}
}