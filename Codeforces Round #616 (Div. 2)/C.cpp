#include<bits/stdc++.h>
using namespace std;
long long n,m,t,k,l,o,r,ans,max1=0; 
long long a[1000001];
int main()
{
    cin>>t;
    while(t--)
    {
    	cin>>n>>m>>k;
    	for(int i=1;i<=n;i++)
    	{
    		cin>>a[i];
    	}
    	max1=0;
    	k=min(k,m-1);
    	for(int j=0;j<=k;j++)
    	{
    		int l=j+1,r=n-(k-j);
    		ans=1e9+7;
    		for(int i=0;i<=m-k-1;i++)
    		{
    			ans=min(ans,max(a[l+i],a[r-(m-k-1-i)]));
    		}
    		max1=max(max1,ans);
    	}
    	cout<<max1<<endl;
    }
}

