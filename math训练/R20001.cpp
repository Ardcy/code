//#include<bits/stdc++.h>
//using namespace std;
//#define int  long long
//int a[1050000][26]={0};
//signed main(){
//
//	int n,m;
//	memset(a,0,sizeof(a));
//	cin>>n>>m;
//	string s,t;
//	cin>>s>>t;
//	int g = __gcd(s.length(),t.length());
//	int ans = s.length()*t.length()/g;
//	if(n==1e6){
//		cout<<s.length()<<" "<<t.length()<<endl;
//		cout<<s.length()*t.length()<<endl;
//		cout<<s.length()*t.length()/g<<endl;
//		cout<<s.length()/g*t.length()<<endl;
//	}
//	int lcm = ans;
//	int lx = s.length();
////	cout<<ans<<endl;
//	for(int i=0;i<s.length();i++){
//		a[i%g][s[i]-'a']++;
//	}
//	if(n==1e6){
//		cout<<ans<<endl;
//	}
//	for(int i=0;i<t.length();i++){
//		ans-=a[i%g][t[i]-'a'];
//	}
//	if(n==1e6){
//		cout<<g<<endl;
//		cout<<ans<<endl;
//		cout<<lcm<<endl;
//		cout<<lx<<" "<<t.length()<<endl;
//			
//	}
//	cout<<(ans*(n*lx/lcm))<<endl;
//	return 0;
//}
#include<bits/stdc++.h>
using namespace std;
#define int  long long
int a[1050000][26]={0};
signed main(){

	int n,m;
	memset(a,0,sizeof(a));
	cin>>n>>m;
	string s,t;
	cin>>s>>t;
	int g = __gcd(s.length(),t.length());
	int ans = (int)s.length()*(int)t.length()/g;
	int lcm = ans;
	int lx = s.length();		
	for(int i=0;i<s.length();i++){
		a[i%g][s[i]-'a']++;
	}
	for(int i=0;i<t.length();i++){
		ans-=a[i%g][t[i]-'a'];
	}
	cout<<(ans*(n*lx/lcm))<<endl;
	return 0;
}
