//#include<bits/stdc++.h>
//using namespace std;
//#define int long long
//int a[105000];
//signed main(){
//	int n,ans;
//	cin>>n;
////	int f = 0;
////	cout<<(1+n)*n<<endl;
//	int w=n;
//	while(n>=0){
//		cout<<n<<endl;
//		int t;
//		for(t=0;n>>t;t++);
//		t--;
//		int x=(1<<(t+1))-1;
//		for(int i=1<<t;i<=n;i++)a[i]=x-i,a[x-i]=i;
//		n=x-n-1;
//	}
//	for(int i=0;i<=w;i++)ans+=i^a[i];
//	cout<<ans<<endl;
//	for(int i=0;i<=w;i++)cout<<a[i]<<" ";
//}
//	int u = log2(w);
//	int t = 1<<u;
////	cout<<bitset<8>(w)<<endl;
////	cout<<bitset<8>(t)<<endl;
//	int w1 = w-t;
//	for(int i=0;i<t;i++){
//		a[i]=i^(t-1);
//	}
//	int t1;
//	for(int i=0;i<t;i++){
//		if(a[i]<=w1){
//			t1=a[a[i]];
//			a[i]+=t;
//			a[t]=i;
//		}
//	}
//	for(int i=0;i<=n;i++){
////		cout<<i<<" "<<a[i]<<endl;
////		cout<<bitset<8>(a[i])<<endl;
////		cout<<bitset<8>(i)<<endl;
//		cout<<a[i]<<" ";		
//	}
//	int ans = 0;
//	for(int i=0;i<=n+f;i++){
//		ans+=a[i]^i;
//	}
//	cout<<ans<<endl;
//	return 0;
//}
#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,x,i,j,k,a[1200000],m,p,y,vn;
signed main(){
	cin>>n;
	vn=n;
	for(i=20;i>=0;--i){
		x=1<<i;
		if(vn>=x){
			p=vn-x+1; m=vn-2*p; y=m;
			for(j=vn;j>m;--j)a[j]=++y;
			vn=m;
		}
	}
	cout<<(n*n+n)<<endl;
	for(i=0;i<=n;++i)printf("%lld ",a[i]);
}
