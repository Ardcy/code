#include<bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;  //防止后面溢出，INF不能太大
const int maxn = 1000+5; //点的个数
bool visit[maxn]; //bool[i]表示是否确定过最短路径
int map1[maxn][maxn]; //用邻接矩阵的方式来存储图
int distance1[maxn]; //distance[i]表示v0到vi的最短路径

void Dijkstra(int n,int beg) //beg表示源结点
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
    for(int i=2;i<=n;i++)  //对其他的n-1个点进行操作
    {
        int Min = INF;
        for(int j=1;j<=n;j++)
        {
            //遍历左右结点，找到离当前源点的最短路径
            if(!visit[j] && distance1[j] < Min)
            {
                v = j;
                Min = distance1[j];
            }
        }
        visit[v] = 1; //加入S集合
        //松弛操作
        for(int j=1;j<=n;j++)
        {
            if(!visit[j] && Min + map1[v][j] < distance1[j]) //利用这次加入的边的Min进行对V-S集合distance的更新
            //每一次MIn是S中最大的，因为之前加入的比后来的小
                distance1[j] = Min + map1[v][j];
        }
    }
}

signed main(){
	
	Dijkstra(1000,3);
	
	cout<<distance1[30]<<endl;
}
