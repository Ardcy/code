#include<bits/stdc++.h>
using namespace std;
#define int long long 
const int N = 2e5+5;
int arr[N];
const int mod = 1e9+7;
int qp(int a,int b){
	int ans = 1;
	while(b){
		if(b&1){
			ans *= a,ans%=mod;
		}
		a*=a,a%=mod;
		b>>=1;
	}
	return ans;
}
struct node{
	int x,y;
	bool operator< (const node &t)const{
		return x<t.x;
	}
}e[100500];
signed main(){
	int t;
	cin>>t;
	while(t--){
		
		int n;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>e[i].x;e[i].y=i;	
		}
		int ans = -1;
		sort(e+1,e+n+1);
		for(int i=1;i<=n;i++){
			if(e[i].x!=e[i-1].x&&e[i].x!=e[i+1].x){
				ans = e[i].y;
				break;
			}
		}
		cout<<ans<<endl;
	}
} 
