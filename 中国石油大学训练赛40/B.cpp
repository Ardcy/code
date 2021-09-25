#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,k;
typedef  long long ll;

int qp(int a,int b,int c){
	int ans = 1;
	while(b){
		if(b&1)ans*=a,ans%=c;
		a*=a;a%=c;
		b>>=1;
	}
	return ans;
}
signed main(){
	cin>>n>>k;
	n--;
	int u=qp(3,n,2*k);
	cout<<u<<endl;
	u=(u+1+2*k)%(2*k);
	u/=2;
	cout<<u<<endl;
	
}

