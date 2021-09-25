#include<bits/stdc++.h>
using namespace std;
#define int long long
#define fi first
#define se second
#define inf INT_MAX
#define mp make_pair
#define pb push_back
const int mod = 998244353;
int qp(int a,int b){int ans=1;while(b){if(b&1)ans*=a,ans%=mod;a*=a,a%=mod;b>>=1;}return ans;};



int g(int a,int b,int c){
	if(a+b<=c)return 0;
	

	
	if(a>b)swap(a,b);
	
	
	if(a>(a+b-c)){
		int f = (a+b)-c;
		return f*(f+1)/2;
		
		
	}else{
		
		return( a+1)*a/2;		
	}

}
signed main(){
	int a,b,c,d;
//	cout<<"  "<<g(2,3,4)<<endl;
	cin>>a>>b>>c>>d;
	int ans = 0;
	for(int i=c;i<=d;i++){
		
		//cout<<i<<endl;
			cout<<g(b,c,i)<<endl;
			cout<<g(a-1,c,i)<<endl;
			cout<<g(b,b-1,i)<<endl;
			cout<<g(a-1,b-1,i)<<endl;
			
			ans+=g(b,c,i)-g(a-1,c,i)-g(b,b-1,i)+g(a-1,b-1,i);
			//cout<<ans<<endl;
	}
	cout<<ans<<endl;
	
	return 0;
}


