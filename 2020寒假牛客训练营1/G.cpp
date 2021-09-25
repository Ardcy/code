#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
__int128 qpow(__int128 a,__int128 b){
	int ans = 1;
	while(b){
		if(b&1) ans *=a;
		a*=a;
		a = a%(mod*mod); 
		ans =ans%(mod*mod);
		b>>=1;
	}
	return ans;
}
int main(){
	long long int a,b,c,d,e,f,g;
	int t;
	cin>>t;
	while(t--){
		cin>>a>>b>>c>>d>>e>>f>>g;
		
		__int128 le,ri;
		le = qpow((__int128)a,(__int128)d)+	qpow((__int128)b,(__int128)e)+qpow((__int128)c,(__int128)f);
		ri  = g;
		if(le==g)cout<<"Yes"<<endl;
		else cout<<"No"<<endl;
	}
}
