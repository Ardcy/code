//#include <bits/stdc++.h>
//using namespace std;
//#define maxn 10000000
//bool vis[maxn];
//int prime[maxn],x;
//void oulasai(int n) { //欧拉筛
//	for(int i=2; i<=n; i++) {
//		if(!vis[i]) prime[x++]=i;
//		for(int j=0; j<x; j++) {
//			if(i*prime[j]>n) break;
//			vis[i*prime[j]]=true;
//			if(i%prime[j]==0) break;
//		}
//	}
//}
//int c[105000];
//bool is_prime(long long x) {
//	if(x==1)
//		return false;
//	if(x==2||x==3)
//		return true;
//	if(x%6!=1&&x%6!=5)
//		return false;
//	int s=sqrt(x);
//	for(int i=5; i<=s; i+=6)
//		if(x%i==0||x%(i+2)==0)
//			return false;
//	return true;
//}
//vector<long long> pfc(long long n) { //快速质因数分解
//	vector <long long> st;
//	long long i=0;
//	if(n==1) {
//		st.push_back(1);
//		return st;
//	}
//	while(i<n) {
//		if(is_prime(n)) {
//			st.push_back(n);
//			return st;
//		}
//		for(i=2; i<n; i++) {
//			if(n%i==0) {
//				st.push_back(i);
//				n/=i;
//				break;
//			}
//
//		}
//	}
//	st.push_back(n);
//	return st;
//}
//int dp[105000];
//int dp2[1050000];
//
//signed main() {
//	int N=1e6;
//	oulasai(N);
//	int n;
//	cin>>n;
//	for(int i=1; i<=n; i++)cin>>c[i];
//	vector<long long> P;
//	for(int i=1; i<=n; i++) {
//		P.resize(0);
//		P=pfc(c[i]);
//		int mi = 1e9;
//
//		for(auto p:P) {
//
//			if(dp2[p]==0)dp2[p]=i;
//			else {
//				dp2[p]=min(dp2[i],i-1);
//			}
//			mi=min(mi,dp2[p]+1);
//		}
//		dp[i]=mi;
//		//cout<<i<<" "<<dp[i]<<endl;
//	}
//	cout<<dp[n]<<endl;
//	return 0;
//
//}
///*
//13
//2 3 4 5 6 7 8 9 10 11  13  17  15
//*/

#include<bits/stdc++.h>
using namespace std;

int splitArray(vector<int>& a) {
	const int SIZE = (1<<20);
	vector<int>p(SIZE);
	for(int i=2; i<=SIZE; i++) {
		if(p[i]==0) {
			for(int j=i; j<=SIZE; j+=i)p[j]=i;
		}
	}
	int inf  = 1e9;
	vector<int>g(SIZE,inf);
	int last_f = 0;
	for(int i=0; i<a.size(); i++) {
		int c = inf;
		for(int m=a[i]; m>1;) {
			int x = p[m];
			g[x]=min(g[x],last_f);
			c=min(c,g[x]+1);
			for(; m%x==0; m/=x);
		}
		last_f=c;
	}
	return last_f;
}



signed main() {
	vector<int>a;
	a.push_back(2);
	a.push_back(3);
	a.push_back(3);
	a.push_back(2);
	a.push_back(3);
	a.push_back(2);
	cout<<splitArray(a)<<endl;
}
