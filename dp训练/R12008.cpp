#include<bits/stdc++.h>
using namespace std;
vector<int>p;
int a[200];

int main(){
	int m,n;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int ans1 = 0,ans2 = 0;
	for(int i=1;i<n;i++){
		if(a[i]%2)ans1++;
		else ans2++;
		if(ans1==ans2){
			p.push_back((abs(a[i+1]-a[i])));
		}		
	}
	sort(p.begin(),p.end());
	p.push_back(10000000);
	int cnt = 0, in = 0 ;
	while(m>=p[in]){
		m-=p[in];
		in++;
		cnt++;
	}
	cout<<cnt<<endl;
}
