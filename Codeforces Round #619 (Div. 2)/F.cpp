#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[105];
signed  main(){
	int T,n,sum;
	cin>>T;
	while(T--){
		sum = 0;
		cin>>n;
		int cnt = 0;
		for(int i=1;i<=n;i++){
			cin>>a[i];
			sum+=a[i];
			if(a[i]==0)cnt++;
		}
		
		if(sum+cnt!=0)cout<<cnt<<endl;
		else cout<<cnt+1<<endl;
	}
}
