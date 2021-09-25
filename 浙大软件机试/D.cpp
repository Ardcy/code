#include<bits/stdc++.h>
using namespace std;
const int N = 2e5+4;
int a[N],b[N];
const int N1 = 1e6+5;
int ans1[N1];
set<int>P;
map<int,int>Q;
const int y = 6e6+3e5+8;
signed main(){
	int n,d;
	cin>>n>>d;
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	for(int i=1;i<=n;i++)scanf("%d",&b[i]);
	sort(a+1,a+n+1);
	sort(b+1,b+n+1);
	for(int i=1;i<=N1;i++)ans1[i]=0;
	int f = 0;
	for(int i=1;i<=n;i++){
		for(int j=n;j>=1;j--){
			f++;
			if(f>y)break;
			P.insert(a[i]-b[j]);
			Q[a[i]-b[j]]++;
		}
		if(f>y)break;
	}
	int cnt = 0;
	for(auto p:P){
		int q = Q[p];
		int p1 = d/p;
		if(p1>=q){
			cnt+=q;d-=q*p;
		}else{
			cnt+=p1;d-=p1*p;
		}
	}
	cout<<cnt<<" "<<d<<endl;
}
