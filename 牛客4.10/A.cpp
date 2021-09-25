#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
	int t;
	cin>>t;
	while(t--){
		int h,a,H,A;
		cin>>h>>a>>H>>A;
		if(A==0||a>=H){
			cout<<-1<<endl;
			continue;
		}
		int cnt = 0;
		int y = H;
		while(h>0){
			H=y;
			while(H>0){
				H-=a;
				if(h<=0||H<=0)break;
				h-=A;
				if(h<=0||H<=0)break;	
			}
			//cout<<H<<" "<<h<<endl;
			if(h>0)cnt++;
		}
		cout<<cnt<<endl;
	}
	return 0;
}
