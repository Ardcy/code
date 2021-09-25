#include<bits/stdc++.h>
using namespace std;
#define int long long
#define fi first
#define se second
#define inf INT_MAX
#define mp make_pair
int a[105000];
signed main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		sort(a+1,a+n+1);
		int cnt = (n+1)/2;
		for(int i=1;i<=n;i++){
			cout<<a[cnt]<<" ";
			if(i%2==1)cnt+=i;else cnt-=i;
		}
		cout<<endl;
	}
	return 0;
}


