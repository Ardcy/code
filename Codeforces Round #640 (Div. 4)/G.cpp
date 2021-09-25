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

int d[] = {3,1,4,2,6,8,5,7};
int a[10];
signed main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		if(n<4){cout<<-1<<endl;continue;}
		if(n==4){
			cout<<"3 1 4 2"<<endl;continue;
		}
		if(n==5){
			cout<<"3 1 4 2 5"<<endl;continue;
		}
		if(n==6){
			cout<<"3 1 4 6 2 5"<<endl;continue;
		}
		if(n==7){
			cout<<"3 1 4 6 2 5 7"<<endl;continue;
		}
		int b = n/8;
		int p = n%8;
		
		for(int i=1;i<=b;i++){
			for(int j=0;j<8;j++){if(i==b&&j==7);else cout<<i*8-8+d[j]<<" ";
			}
		}
		a[0]=b*8-1;
		int a1 = a[0];
		int cnt = 0;
		for(int i=a1;i<=n;i++){
			if(i<=a1/8*8+8&&i!=a1)continue;
			a[cnt]=i;
			cnt++;
		}
		do{
			int f = 1;
			for(int i=1;i<cnt;i++){	
				if(abs(a[i]-a[i-1])<2||abs(a[i]-a[i-1])>4)f=0;
			}
			if(f==1)break;
		}while(next_permutation(a,a+cnt));
//		for(int j=0;j<7;j++)cout<<b*8-8+d[j]<<" ";
		for(int i=0;i<cnt;i++)cout<<a[i]<<" ";
		cout<<endl; 
		
		
		
		
	}
	return 0;
}


