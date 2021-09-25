#include<bits/stdc++.h>
using namespace std;
#define pb push_back
int n;
int Prime[2010];
struct edge{
int a,b;};
vector<edge>Ans;
void add(int a,int b){
	Ans.pb({a,b});
}
signed main(){
	int i,j;
	cin>>n;
	for(i=2;i<=2000;i++){
		for(j=2;j*j<=i;j++){
			if(i%j==0)break;
		}
		if(j*j>i)Prime[i]=1;
	}
	for(i=1;i<=n;i++)add(i,i%n+1);
	int p1 = 1, p2 = n/2+1;
	for(i=n;;i++){
		if(Prime[i])break;
		add(p1,p2);
		p1++,p2++;
	}
	cout<<Ans.size()<<endl;
	for(auto p:Ans)cout<<p.a<<" "<<p.b<<endl;
}
