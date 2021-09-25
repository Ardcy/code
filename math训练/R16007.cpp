#include<bits/stdc++.h>
using namespace std;
vector<int> v[205000];
int a[205000];
int main(){
	int n,k,ans = 2e9;
	cin>>n>>k;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		int x = a[i],t=0;
		while(x){
			v[x].push_back(t);
			x/=2;
			t++;
		}
	}
	for(int i=0;i<200005;i++){
		if(v[i].size()>=k){
			int sum=0;
			sort(v[i].begin(),v[i].end());
			for(int j=0;j<k;j++){
				sum=sum+v[i][j];
			}
			ans=min(ans,sum); 
		}
	}
	cout<<ans<<endl;
	
}
