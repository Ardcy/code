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


MST��С������֪ʶ�� prim�㷨�����Ż���&&Kruskal�㷨;
��1��prim�㷨���Ż�## ���ģ��㼯������ ��ѡһ�㿪ʼ����ѡ�㼯��δѡ�㼯֮��ı�Ȩ�������� ����Ȩ��Ӧ��С�ı߶�Ӧ��δѡ�㼯�������ѡ�㼯�У�ֱ��������Ϊ����-1
���У���Ȩ��ͨ������������Ż���priority_queue��,ʹ����logn���ٶ��ұ�Ȩ��С��
��2��kruskal�㷨##���ģ��߼������䣬�����б�Ȩ�������򣬴�С����ӱߣ�ͬʱȷ���߼�������ֻ�
��ϰ
P3366��С������ģ����
P2872 [USACO07DEC]��·����Building Roads
���в��ֱ����� ����С��������Ȩ�ͣ������б�Ȩ��0����
P1991 ����ͨѶ��
���ֱ����� ����С������ǰkС�ı��е����� ����С��������Ȩ�������¼ ���sort����
bzoj1116: [POI2008]CLO
��������ͼ���ж��Ƿ���ڽ����ֱ߱�Ϊ�����ʹ�����е�����Ϊ1
�ȼ����Ƿ���ڻ�
���鼯�ж�����ͼ���Ƿ���ڻ�����Kruskal�� ���ò��鼯������С���������л���ʵֻ��Ҫ�ж�Ҫ���������ߵ��������Ƿ�����ͬһ�����ڵ㼴�ɣ�����һ��vis����ά������
bzoj2429 �����ĺ���
MSTģ���� ����С������֮���������ߵĺ�����Ծ�������
