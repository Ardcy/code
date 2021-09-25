#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[200];
signed main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		int f=0,in=0;
		for(int i=1;i<=n;i++){
			cin>>a[i];
			if(a[i]%2==0)f=1,in=i;	
		}
		if(f)cout<<1<<"\n"<<in<<endl;
		else if(n>=2)cout<<2<<"\n"<<1<<" "<<2<<endl;
		else cout<<-1<<endl; 
		
	}
	return 0;
}
