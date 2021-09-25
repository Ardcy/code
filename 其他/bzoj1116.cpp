#include<bits/stdc++.h>
using namespace std;
#define N 100050
int fath[N],n,m,v[N];
void ini(){
	for(int i=1;i<=N;i++)fath[i]=i;
}
int father(int x){
	if(x!=fath[x])fath[x]=father(fath[x]);
	return fath[x];
}
void unione(int x,int y){
	if(father(x)!=father(y))
		v[father(y)]=v[father(x)]|v[father(y)],fath[father(x)]=father(y);
	else
		v[father(x)]=1;
}
int main(){
	ini();
	cin>>n>>m;
	for(int i=1,x,y;i<=m;i++){
		cin>>x>>y;
		unione(x,y);
	}
	int flag=1;
	for(int i=1;i<=n;i++){
		if(!v[father(i)])flag=0;
	}
	if(flag)
		cout<<"TAK"<<endl;
	else
		cout<<"NIE"<<endl;
	return 0; 
}


MST最小生成树知识点 prim算法（堆优化）&&Kruskal算法;
（1）prim算法堆优化## 核心：点集的扩充 任选一点开始按已选点集与未选点集之间的边权进行排序 将边权对应最小的边对应的未选点集点加入已选点集中，直至边数成为点数-1
其中，边权可通过堆排序进行优化（priority_queue）,使得以logn的速度找边权最小边
（2）kruskal算法##核心：边集的扩充，将所有边权进行排序，从小到大加边，同时确保边集不会出现环
练习
P3366最小生成树模板题
P2872 [USACO07DEC]道路建设Building Roads
已有部分边连接 求最小生成树边权和：将已有边权置0即可
P1991 无线通讯网
部分边连接 求最小生成树前k小的边中的最大边 将最小生成树边权用数组记录 最后sort即可
bzoj1116: [POI2008]CLO
给定无向图，判断是否存在将部分边变为单向边使得所有点的入度为1
等价于是否存在环
并查集判断无向图中是否存在环：在Kruskal中 利用并查集构造最小生成树，判环其实只需要判断要连的那条边的两个点是否来自同一个根节点即可，利用一个vis数组维护即可
bzoj2429 聪明的猴子
MST模板题 求最小生成树之后求大于最长边的猴子跳跃距离个数
