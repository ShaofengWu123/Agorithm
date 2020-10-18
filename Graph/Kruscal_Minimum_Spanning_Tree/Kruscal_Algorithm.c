#include <stdio.h>
#include <stdlib.h>

#define V 6
#define N 8


typedef struct _e {
	int weight;
	int node1;
	int node2;
}Line;

//��������
void Kruscal(Line a[],int n);
void Sort1(Line a[], int n);
int Quick_sort1(Line a[], int min, int max);
int MIN(int a, int b);



int MIN(int a,int b) {
	return a < b ? a : b;
}
/*Kruscal�㷨:
1.�����б�����
2.ѡ��һ���ߣ����㣺a.���˵㲻���Ѳ�������ͨƬ�ڡ�b.����a���������̣����������aֱ�����������ߣ���Ϊ����Ҳ����Ҫ�õ���������
3.������ͨƬ��ţ���������һ����ѡ��v-1����ʱ�㷨����������ص��ڶ���
*/
void Kruscal(Line a[],int n){
	//Sort, limit the complexity of Kruscal algorithm
	Sort1(a,n);
	int counter = 0;
	int Nodes_section[V];
	for (int k = 0; k < V; k++) {
		Nodes_section[k] = k;
	}
	int i = 0;
	while (counter < V-1) {
			//Select mini, or say a[i] because already sorted
			if(Nodes_section[a[i].node1]!= Nodes_section[a[i].node2]){
				//select
				printf("��С�������� %d �ڵ�� %d �ڵ�֮��ľ�����: %d\n", a[i].node1, a[i].node2,a[i].weight);
				Nodes_section[a[i].node1] = Nodes_section[a[i].node2] = MIN(Nodes_section[a[i].node1], Nodes_section[a[i].node2]);
				counter++;
			}
			i++;
	}
}

void Sort1(Line a[],int n){
	Quick_sort1(a,0,n-1);
}

int Quick_sort1(Line a[],int min,int max) {
	Line temp;
	if (min >= max) { return 0; }
	int j = min ; int k = max ;
	int v = a[min].weight;
	while (1) {
		//�ƶ��������λ�ã�ֱ������������
		while (a[++j].weight < v) { if (j == max-1) break; }
		while (a[--k].weight > v) { if (k == min) break; }
		if (j >= k) { 
			break;
		}
		temp = a[j];
		a[j] = a[k];
		a[k] = temp;
	}
	//ȷ���ָ�λ��
	temp = a[k];
	a[k] = a[min];
	a[min] = temp;
	//�ݹ����
	Quick_sort1(a,min,k-1);
	Quick_sort1(a,k+1,max);
	return 1;
}

int main() {
	//��������ͼ��2.3��2.5
	Line a[N] = { {1,0,1} ,{2,0,5},{2,1,5},{3,1,2},{3,2,5},{4,2,3},{5,3,4},{5,4,5} };
	Kruscal(a,N);
}