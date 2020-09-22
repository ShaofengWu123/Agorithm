#include "Arrayops.h"
void Bubble_sort(int a[], int n) {
	//Bubble sort/ц╟ещеепР: 
	for (int k=0;k<n-1;k++) {
		for (int i = 0; i < n - 1 - k; i++) {
			if (a[i] > a[i + 1]) { exc(&a[i],&a[i+1]); }
		}
	}
}
