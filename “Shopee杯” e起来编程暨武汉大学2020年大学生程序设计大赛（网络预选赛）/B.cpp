#include<bits/stdc++.h>
using namespace std;
#define int long long
#define fi first
#define se second
#define inf INT_MAX
#define mp make_pair
#include<ctime>
int a[100]={0};
signed main(){
	srand( time( NULL ) );
	int ans1 = 0;
	int t = 100000000;
	for(int i=1;i<=t;i++){
		ans1=i*(rand())%(i-2);
	}
	ios::sync_with_stdio(false);
	int n;
	cin>>n;
	int ans = 0;
	int b;
	for(int i=1;i<=n;i++){
		cin>>b;
		b+=30;
		a[b]++; 
	} 
	for(int i=10;i<=29;i++){
		ans+=a[i]*a[60-i];
	}
	if(a[30])ans+=(a[30]*a[30]-a[30])/2;
	cout<<ans<<endl;
	return 0;
}

