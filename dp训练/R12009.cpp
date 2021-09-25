#include<bits/stdc++.h>
using namespace std;
map<string,int>p;
int main(){
	int n;
	cin>>n;
	string a;
	int b;
	p["A"]=1000000;
	p["AB"]=1000000;
	p["ABC"]=1000000;
	p["AC"]=1000000;
	p["B"]=1000000;
	p["BC"]=1000000;
	p["C"]=1000000;
	for(int i=1;i<=n;i++){
		cin>>b>>a;
		sort(a.begin(),a.end());

		p[a]=min(p[a],b);
		//cout<<a<<" "<<p[a]<<endl;

	}
	int ans = 1000000;
	ans = min(ans,p["A"]+p["BC"]);
	//cout<<"1 "<<ans<<endl;
	ans = min(ans,p["B"]+p["AC"]);
	//cout<<"2 "<<ans<<endl;
	ans = min(ans,p["C"]+p["AB"]);
	//cout<<"3 "<<ans<<endl;
	ans = min(ans,p["A"]+p["B"]+p["C"]);
	//cout<<"4 "<<ans<<endl;
	ans = min(ans,p["ABC"]);
	//cout<<"5 "<<ans<<endl;
	if(ans<1000000)cout<<ans<<endl;
	else cout<<-1<<endl;
}
