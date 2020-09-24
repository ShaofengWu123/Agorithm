void Shellsort(int a[], int n) {
	int h = n/2;
    //h = 3*h+1;序列性能较优
	while (h >= 1) {
		for (int i = h; i < n; i++) {
			for (int j = i;j>=h&&a[j]<a[j-h];j-=h) {
				exc(&a[j], &a[j - h]);
			}
		}
		h /= 2;
	}	
}