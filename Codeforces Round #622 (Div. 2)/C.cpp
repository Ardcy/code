#include<bits/stdc++.h>
#define debug(x) cerr<<#x<<"="<<x<<endl
using namespace std;
#define int long long
int a[250];
int b[250];
int c[250];
signed main(){
	int t;
	cin>>t;
	while(t--){
		int f;
		cin>>f;
		memset(b,0,sizeof(b));
		for(int i=1;i<=f;i++){
			cin>>a[i];
			b[a[i]]=1;		
		}
		//for(int i=1;i<=2*f;i++)cout<<b[i]<<endl;
		int cnt=0;
		for(int i=1;i<=f;i++){
			for(int j=a[i]+1;j<=2*f;j++){
				if(b[j]==0){
					//debug(j);
					b[j]=1,c[i]=j,cnt++;
					j=2*f+1;
				}
			}	
		}
		if(cnt!=f){
			cout<<-1<<endl;
		}
		else {
			for(int i=1;i<=f;i++){
				cout<<a[i]<<" "<<c[i]<<" ";
			}
			cout<<endl;
		}
	}
	return 0;
}
