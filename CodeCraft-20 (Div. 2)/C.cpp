#include<bits/stdc++.h>
using namespace std;
#define int long long
const int MAXN=2*1e6+10;
inline int read()
{
    char c=getchar();int x=0,f=1;
    while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
    while(c>='0'&&c<='9'){x=x*10+c-'0';c=getchar();}
    return x*f;
}
int a[1005000];
int b[1005000];
int p; 
int ans=0,an=0;
int f1=0,f2=0;
signed main()
{
    int N=read(),M=read();
    p=read();
    for(int i=0;i<N;i++) {
    	a[i]=read();
		if(a[i]%p!=0&&f1==0)an=i,f1=1;	
	}
    for(int i=0;i<M;i++){
    	b[i]=read();
		if(b[i]%p!=0&&f2==0)ans=i,f2=1;
	} 
	cout<<ans+an<<endl;
    return 0;
}
