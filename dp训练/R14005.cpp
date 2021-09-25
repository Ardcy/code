#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[10500];

signed main(){
	int n,m,d;
	cin>>n>>m>>d;
	int b;
	int ans = 0;
	cin>>a[1];
	b=(a[1]%d+d)%d;
	a[1]=(a[1]-b)/d;
	ans += (a[1]-b)/d;
	int flag=0;
	int mae = 0;
	for(int i=2;i<=n*m;i++){
		cin>>a[i]; 
		if(((a[i]%d)+d)%d!=b){
			flag=1;
		}
		ans+=a[i]/d;
		a[i]=(a[i]-((a[i]%d)+d)%d)/d;
		mae=max(mae,a[i]);
	}
	if(flag){
		cout<<-1<<endl;
	}
	else{
		int ans1=1000000000,ans2=0;
		for(int i=1;i<=mae+1;i++){
			ans2=0;
			for(int j=1;j<=m*n;j++)ans2+=abs(a[j]-i);
			ans1=min(ans1,ans2);
		}
		cout<<ans1<<endl;
		
	}
	return 0;
}
