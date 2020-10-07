void Shell_sort(int a[], int n) {
	//Shell sort/希尔排序。改进版的插入排序，利用递增序列构造h有序数组。
	//时间复杂度：O(n^a),1<a<2。
	//特点：比插入排序更快，原地排序，但不是稳定的排序
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