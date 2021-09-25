#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
	string a,b;
	cin>>a>>b;
	if(a.length()!=b.length()){
		cout<<"NO"<<endl;
		return 0;
	}
	else{
		int cnt1=0,cnt2=0;
		for(int i=0;i<a.length();i++){
			if(a[i]=='1')cnt1++;
			if(b[i]=='1')cnt2++;
		}
		if(cnt1==0&&cnt2==0)cout<<"YES"<<endl;
		else if(cnt1*cnt2==0)cout<<"NO"<<endl;
		else cout<<"YES"<<endl; 
	}
}
