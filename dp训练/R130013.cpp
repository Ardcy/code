#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[100][100];
signed main(){
	string s;
	string t;
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		if(i==1){
			cin>>s;
			if(n==1){
				cout<<0<<endl;
				return 0;	
			}
			continue;
		}
		int l=s.length();
		cin>>t;
		int ff=0;
		int ff1=0;
		for(int j=1;j<=s.length();j++){
			s=s.substr(1,s.length()-1)+s[0];
			if(s==t)a[i][ff++]=j;	
		}
		if(ff==0){
			cout<<-1<<endl;return 0;
		}
	}
	int l=s.length();
	a[1][0]=l;
	int ans=10000000000;
	for(int i=1;i<=l;i++){
		int ans1=0;
		for(int j=1;j<=n;j++){
			int max3 = 200;
			for(int k=0;k<100;k++){
				if(a[j][k]==0)break;
				max3=min((i-a[j][k]+l)%l,max3);
			}
			ans1+=max3;
		}
		ans=min(ans1,ans);
	}
	cout<<ans<<endl;
//	for(int i=1;i<=n;i++){
//		cout<<a[i]<<endl;
//	}
//	
}
