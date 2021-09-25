#include<bits/stdc++.h>
using namespace std;
#define int long long 
const int N = 2e5+5;
int arr[N];
const int mod = 1e9+7;
int ans[N];
signed main(){
	int t;
	cin>>t;
	
	while(t--){
		
		int n;
		cin>>n;
		int ans1 = n;
		int sum = 0;
		int y = sqrt(n);
		vector<pair<int,int> >P;
		for(int i=2;i<=y+1;i++){
			if(n%i==0){
				int cnt = 0;
				while(n%i==0)cnt++,n/=i;
					
				sum+=cnt;
				P.push_back(make_pair(cnt,i));
			}
		}
		
		if(n!=1)P.push_back(make_pair(1,n));
		int ans = 0;
		int f1 = 0;
		
		for(auto p:P){
			if(ans < p.first)
			{
				ans = p.first;
				f1 = p.second;
			}
		}
		
		cout<<ans<<endl; 
		for(int i=1;i<ans;i++){
			cout<<f1<<" ";
			ans1/=f1;
		}
		cout<<ans1<<endl;
		
	}
} 
