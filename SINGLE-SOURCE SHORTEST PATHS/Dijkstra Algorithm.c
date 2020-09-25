#include <stdio.h>
#include "Arrayops.h"

#define NPoints 6
#define Inf 1000

int main() {
	//初始化图，这里的具体数据来自图论Dijkstra算法习题chap1.26
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
	//开始循环,共需要NPoints-1次循环
	for (int i = 0; i < NPoints - 1; i++) {

		int MIN = Inf;
		int MIN_index=0;
		for (int j = 0; j < NPoints; j++) {
			
			if (!S[j]) {//即j对应点还没有确定好最短路径，在S数组内用0标记表示没有确定好最短路径。
				if (d[prior] + path[prior][j]<d[j]) {//比较已知最短路径与新路径，若新路径更短那么更新已知最短路径，否则什么也不做
					d[j] = d[prior] + path[prior][j];
					L[j] = prior;
				}
				//实时更新V-S中最小路径的值
				if (min(MIN, d[j]) == d[j]) { MIN = d[j]; MIN_index = j; }
			}
			else { ; }

		}

		printf("到%d节点的最短路径长度是%d，前驱节点是%d\n",MIN_index,d[MIN_index],L[MIN_index]);
		prior = MIN_index; S[MIN_index] = 1;

	}

	return 0;
}