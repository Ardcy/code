#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m;
int mid;
signed main(){
	cin>>n>>m;
	if(n<=m)cout<<n<<endl;
	else{
		int l=1,r=INT_MAX;
		while(l<r){
			mid=(l+r)/2;
			if(mid*(mid+1)/2>=n-m){
				r=mid;
			}
			else 
				l=mid+1;
		}
		cout<<l+m<<endl;
	} 
	
	
}
