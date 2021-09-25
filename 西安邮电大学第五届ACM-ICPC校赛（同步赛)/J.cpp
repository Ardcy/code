#include<bits/stdc++.h>
using namespace std;
#define int long long
#define fi first
#define se second
#define inf INT_MAX
#define pb push_back
const int mod = 998244353;
int qp(int a,int b){int ans=1;while(b){if(b&1)ans*=a,ans%=mod;a*=a,a%=mod;b>>=1;}return ans;};

//int snum[10];
signed main(){
	int n;
	while(cin>>n){
		if(n==0)break;
		//for(int i=1;i<=10;i++)snum[i]=0;
		int snum = 0,lnum = 1;
		int f = 1;
		for(int i=1;i<=5;i++){
			
		
			if(i==4){
				snum-=1;
				lnum+=1;
			}
			if(i>4){
				snum-=1;
				lnum+=1;
			}
			snum+=lnum;	
			n-=(snum+lnum)*3;
			if(n<0){
				cout<<"AOLIGEI!"<<endl,f=0;
				break;
			}
			cout<<snum<<" "<<lnum<<endl;
			cout<<n<<endl;
			
		}
		if(f){
			cout<<"DAAAAAMN!"<<endl;
		}
	}
}


