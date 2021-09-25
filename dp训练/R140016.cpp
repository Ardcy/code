#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[200];
int b[200];
int c[200];
signed main(){
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		b[a[i]]++;
	}
	int cnt = 0;
	int e = 0;
	for(int i=1;i<=100;i++){
		if(b[i]==1)cnt++;
		if(b[i]>2)e=1;
	}
	if(cnt%2==0){
		int r=cnt/2;
		cout<<"YES"<<endl;
		for(int i=1;i<=n;i++){
			if(b[a[i]]!=1||r==0)cout<<"A";
			else{
				cout<<"B";r--;
			}
		}
	}else{
		if(!e)cout<<"NO"<<endl;
		else{
			int r=cnt/2;
			int rr=1;
			cout<<"YES"<<endl;
			for(int i=1;i<=n;i++){
				if(b[a[i]]==1&&r){
					cout<<"A";
					r--;	
				}
				else{
					if(b[a[i]]>=3&&rr){
						cout<<"A";rr--;
					}
					else cout<<"B";
				}
			}	
			
		}
	}
	
	
	return 0;
}
