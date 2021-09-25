#include<bits/stdc++.h>
using namespace std;
#define int long long
#define fi first
#define se second
#define inf INT_MAX
#define mp make_pair
#define pb push_back
const int mod = 998244353;
int qp(int a,int b){int ans=1;while(b){if(b&1)ans*=a,ans%=mod;a*=a,a%=mod;b>>=1;}return ans;};

int p[11]={0};
int c(){
	int val = 1;
	for(int i=1;i<=10;i++)val*=p[i];
	return val;
}
signed main(){
	int t;
	//cin>>t;
	t = 1;
	while(t--){
		int n;
		cin>>n;
		
		for(int i=1;i<=10;i++)p[i]=1;
		int ans = 0;
		while(1){
			ans = c();
			if(ans>=n){
				break;
			}
			for(int i=1;i<=10;i++){
				p[i]++;
				ans = c();
				if(ans>=n){
					break;
				}
			}
		}
		
	}
	
	for(int i=1;i<=p[1];i++)cout<<'c';
	
	for(int i=1;i<=p[3];i++)cout<<'o';
	for(int i=1;i<=p[7];i++)cout<<"d";
	for(int i=1;i<=p[5];i++)cout<<'e';
	for(int i=1;i<=p[8];i++)cout<<"f";
	for(int i=1;i<=p[4];i++)cout<<'o';
	for(int i=1;i<=p[9];i++)cout<<'r';
	for(int i=1;i<=p[2];i++)cout<<'c';
	for(int i=1;i<=p[6];i++)cout<<'e';
	for(int i=1;i<=p[10];i++)cout<<'s';cout<<endl;
	return 0;
}


