#include <stdio.h>
#include "Arrayops.h"

#define NPoints 6
#define Inf 1000

int main() {
	//��ʼ��ͼ������ľ�����������ͼ��Dijkstra�㷨ϰ��chap1.26
	int path[NPoints][NPoints] = 
	{0,  50, Inf, 40, 25, 10,
	 50,0,   15, 20, Inf, 25,   
	 Inf,15, 0,   10, 20, Inf,
	40, 20, 10, 0,   10, 25,
	25, Inf, 20, 10, 0,  55,
	10,25,   Inf, 25, 55, 0,
	};
	int d[NPoints] = {0,Inf,Inf,Inf,Inf,Inf,};
	int L[NPoints] = {-1,-1,-1,-1,-1,-1};
	int S[NPoints] = {1,0,0,0,0,0,};
	int prior = 0;
	//��ʼѭ��,����ҪNPoints-1��ѭ��
	for (int i = 0; i < NPoints - 1; i++) {

		int MIN = Inf;
		int MIN_index=0;
		for (int j = 0; j < NPoints; j++) {
			
			if (!S[j]) {//��j��Ӧ�㻹û��ȷ�������·������S��������0��Ǳ�ʾû��ȷ�������·����
				if (d[prior] + path[prior][j]<d[j]) {//�Ƚ���֪���·������·��������·��������ô������֪���·��������ʲôҲ����
					d[j] = d[prior] + path[prior][j];
					L[j] = prior;
				}
				//ʵʱ����V-S����С·����ֵ
				if (min(MIN, d[j]) == d[j]) { MIN = d[j]; MIN_index = j; }
			}
			else { ; }

		}

		printf("��%d�ڵ�����·��������%d��ǰ���ڵ���%d\n",MIN_index,d[MIN_index],L[MIN_index]);
		prior = MIN_index; S[MIN_index] = 1;

	}

	return 0;
}