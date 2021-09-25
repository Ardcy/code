#include<bits/stdc++.h>
using namespace std;
priority_queue<int,vector<int>, greater<int> > q;
int n,k,a[200005],g[200005],b[200005],c[200005];
int main()
{
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		g[a[i]]++;
	}
	for(int i=1,j=0;i<=n;i++)
	{
		g[a[i]]--;
		q.push(a[i]);
		if(g[a[i]]==0&&c[a[i]]==0)
		{
			while(1)
			{
				int tt;
				while(1)
				{
					int t=q.top();
					if(b[t]>0||c[t])
					{
						b[t]--;
						q.pop();
					}
					else
					{
						tt=t;
						break;
					}
				}
				while(1)
				{
					j++;
					b[a[j]]++;
					if(a[j]==tt)
					{
						printf("%d ",a[j]);
						c[a[j]]=1;
						break;
					}
				}
				if(tt==a[i])
					break;
			}
		}
	}
}