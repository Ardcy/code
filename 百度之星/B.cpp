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

double b[500]={0};
double a[200]={0};
signed main(){
	
	for(int i=0;i<60;i++)a[i]=0;
	for(int i=60;i<62;i++)a[i]=1.0;
	for(int i=62;i<=64;i++)a[i]=1.7;
	for(int i=65;i<=66;i++)a[i]=2.0;
	for(int i=67;i<=69;i++)a[i]=2.3;
	for(int i=70;i<=74;i++)a[i]=2.7;
	for(int i=75;i<=79;i++)a[i]=3.0;
	for(int i=80;i<=84;i++)a[i]=3.3;
	for(int i=85;i<=89;i++)a[i]=3.7;
	for(int i=90;i<=94;i++)a[i]=4.0;
	for(int i=95;i<=100;i++)a[i]=4.3;
	for(int i=0;i<=100;i++){
		for(int j=0;j<=100;j++){
			for(int z=0;z<=100;z++){
				
				for(int w=0;w<=100;w++){
					b[i+j+z+w]=max(a[i]+a[j]+a[z]+a[w],b[i+j+z+w]);
				}
				
				
			}
		}	
	}
	
	//for(int i=300;i<=400;i++)cout<<b[i]<<endl;
	
	int t;
	
	
	
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		printf("%.1f\n",b[n]);
	}
	return 0;
}


