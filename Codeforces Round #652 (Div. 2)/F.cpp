#include<bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;  //��ֹ���������INF����̫��
const int maxn = 1000+5; //��ĸ���
bool visit[maxn]; //bool[i]��ʾ�Ƿ�ȷ�������·��
int map1[maxn][maxn]; //���ڽӾ���ķ�ʽ���洢ͼ
int distance1[maxn]; //distance[i]��ʾv0��vi�����·��

void Dijkstra(int n,int beg) //beg��ʾԴ���
{
	for(int i=1;i<=1000;i++){
		for(int j=1;j<=1000;j++){
			if(i!=j)map1[i][j]=INF;
		}
	}
    for(int i=1;i<n;i++){
        map1[i][i+1]=1;
        map1[i+1][i]=1;
        if(i*i<=n)map1[i][i*i]=1;
    }
    
    for(int i=1;i<=n;i++)
    {
        distance1[i] = map1[beg][i];
        visit[i] = false;
    }
    visit[beg] = true;
    distance1[beg] = 0;
    int v;
    for(int i=2;i<=n;i++)  //��������n-1������в���
    {
        int Min = INF;
        for(int j=1;j<=n;j++)
        {
            //�������ҽ�㣬�ҵ��뵱ǰԴ������·��
            if(!visit[j] && distance1[j] < Min)
            {
                v = j;
                Min = distance1[j];
            }
        }
        visit[v] = 1; //����S����
        //�ɳڲ���
        for(int j=1;j<=n;j++)
        {
            if(!visit[j] && Min + map1[v][j] < distance1[j]) //������μ���ıߵ�Min���ж�V-S����distance�ĸ���
            //ÿһ��MIn��S�����ģ���Ϊ֮ǰ����ıȺ�����С
                distance1[j] = Min + map1[v][j];
        }
    }
}

signed main(){
	
	Dijkstra(1000,3);
	
	cout<<distance1[30]<<endl;
}
