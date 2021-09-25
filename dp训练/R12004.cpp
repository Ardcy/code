#include<bits/stdc++.h>
using namespace std;
int d[20]={0};
int main(){
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)cin>>d[i];
	for(int i=1;i<(1<<n);i++){
		int ans = 0;
		for(int j = 1,f=1;j<(1<<n);j<<=1,f++)
		{
			//cout<<j<<endl; 
			if(j&i)ans+=d[f];
			else ans-=d[f];
			//cout<<ans<<endl;
		}
		//cout<<ans<<endl;
		if(ans%360==0){
			cout<<"YES"<<endl;
			return 0;
		}
	}
	cout<<"NO"<<endl;
}
