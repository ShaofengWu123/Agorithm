void Shell_sort(int a[], int n) {
	//Shell sort/ϣ�����򡣸Ľ���Ĳ����������õ������й���h�������顣
	//ʱ�临�Ӷȣ�O(n^a),1<a<2��
	//�ص㣺�Ȳ���������죬ԭ�����򣬵������ȶ�������
	int h = n/2;
    //h = 3*h+1;�������ܽ���
	while (h >= 1) {
		for (int i = h; i < n; i++) {
			for (int j = i;j>=h&&a[j]<a[j-h];j-=h) {
				exc(&a[j], &a[j - h]);
			}
		}
		h /= 2;
	}	
}