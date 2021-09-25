//#include<bits/stdc++.h>
//using namespace std;
//#define int long long
//#define fi first
//#define se second 
//int a[105000];
//struct cmp1{
//	bool operator()(const int& a,const int&b){
//		return a>b;
//	}
//};
//struct cmp2{
//	bool operator()(const int& a,const int&b){
//		return a>b;
//	}
//};
//map<int,int,cmp1>b;
//signed main(){
//	int n;
//	cin>>n;
//	for(int i=1;i<=n;i++)cin>>a[i],b[a[i]]++;
//	set<int,cmp2>v;
//	for(auto p:b)if(p.se%2)v.insert(p.fi),p.se--;
//	map<int,int>yt;
//	for(auto p:v){
//		if(yt[p])continue;
//		yt[p]=1;
//		if(v.find(p-1)!=v.end()){
//			b[p-1]+=2;
//			yt[p-1]=1;
//		}
//	}
//	int pre = 0;
//	int ans = 0;
//	for(auto p:b){
//		p.se/=2;
//		if(p.se==0)continue;
//		if(pre != 0){
//			ans+=pre*p.fi;p.se--;pre=0;
//		}
//		if(p.se%2==0){
//			ans+=p.fi*p.fi*(p.se/2);
//		}
//		else{
//			ans+=p.fi*p.fi*(p.se/2);
//			pre = p.fi;
//		}
//	}
//	cout<<ans<<endl;
//	return 0;
//}
#include<bits/stdc++.h>
using namespace std;
#define int long long
const int maxn = 1e5+5;
int n,m=0,a[maxn];
int ans = 0,mul = 1;
signed main(){
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=n;i>0;--i){
		if(a[i]-a[i-1]<=1)mul*=a[i-1],i--,m++;
		if(m==2)ans+=mul,mul=1,m=0;
	}
	cout<<ans<<endl;
}
