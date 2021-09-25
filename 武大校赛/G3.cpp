#include<bits/stdc++.h>
using namespace std;
#define int long long
#define fi first
#define se second
#define inf INT_MAX
#define mp make_pair
int a[1000];
int b[1000];
int c[1000];
vector<int>P;
signed main(){
	int n;
	cin>>n;
	int ma = -1e9;
	int u;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		//ma=max(u,ma);
	}
	
	for(int i=1;i<=n;i++){
		cin>>b[i];
		
	}
	
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}
	sort(a+1,a+n+1);
	sort(b+1,b+n+1);
	sort(c+1,c+n+1);
	int x,y,z;
	int ans1=-1e13,ans2=1e13,ans3=1e13;;
	int ans11=-1e13,ans22=-1e13,ans33=-1e13;
	for(int i=1;i<=n;i++){
		x=a[i];
		ans2=1e13;
		for(int j=1;j<=n;j++){
			y=b[j];
			ans3=1e13;
			for(int k=1;k<=n;k++){
				z=c[k];
				if(abs(x+y+z)<=abs(x+y+ans3)){
					ans3=z;
				}	
			}
			//cout<<"ans3="<<ans3<<endl;
			//if(x==2&&y==-5)cout<<ans3<<endl;
			if((x+y+ans3)<=(x+ans2)){
				ans2=y+ans3;
			}
		}
		//cout<<"ans2="<<ans2<<endl;
		if(x+ans2>=ans1){
			ans1=x+ans2;
		}
//		if(ans11+ans22+ans33<=ans1+ans2+ans3){
//			ans11=ans1,ans22=ans2,ans33=ans3;
//		}
	}
	cout<<ans1<<endl;
//	cout<<(ans11+ans22+ans33)<<endl;
	return 0;
}


