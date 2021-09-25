#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,p,ans=1;
	cin>>n>>p;
	while(n-ans*p>0){
		if(__builtin_popcountll(n-ans*p)<=ans){
			if(n-ans*p>=ans){
				return cout<<ans<<endl,0;
			}
		}
		ans++;
	}
	cout<<-1<<endl;	
}

