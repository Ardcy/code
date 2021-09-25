#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
	int t;
	cin>>t;
	while(t--){
		int n,l,r;
		cin>>n>>l>>r;
		int le = r+1-l;
		int rr = 0;
		int t2 = 0;
		int er = n-1;
		while(t2<l){
			if(t2+2*er>=l)break;
			else t2+=2*er,er--;
			//cout<<er<<" "<<t2<<endl;
			if(er<0)break;
			
		}
		er++;
		if(l==n*(n-1)+1){
			cout<<1<<endl;continue;
		}
		int u = r,u1=0;
		if(r==(n*n-n+1))r--,u1=1;
		int t1 = t2;
		int k=n+1-er;
		int ff = 1;
		//cout<<k<<endl;
		while(ff){
			for(int i=1;i<=2*(n-k);i++){
				t1++;
				//cout<<"t1="<<t1<<endl;
				if(t1>=l&&t1<=r){
					if(i%2==0)cout<<k+(i)/2<<" ";
					else cout<<k<<" ";	
				}
				if(t1>r){
					if(u1==1)cout<<1;
					cout<<endl;
					ff=0;break;
				}
			}
			if(t1==r){
				if(u1==1)cout<<1;
				cout<<endl;
				ff=0;break;
			}
			k++;
		}
	}	
}
