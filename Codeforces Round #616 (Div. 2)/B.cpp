#include<bits/stdc++.h>
using namespace std;
void solve(){
	int k,j;
	cin>>k;
	int flag = 0;
	if(k%2){
		
		for(int i=1;i<=k;i++){
			cin>>j;
			int h =(k+1)  / 2;
			if(i<=h&&j<i-1) flag = 1;
			if(i>h&&j<k-i)flag = 1;	
		}
		if(flag)cout<<"No"<<endl;
		else cout<<"Yes"<<endl;
	}
	else{
		
		int u = 0, p = 0;
		for(int i=1;i<=k;i++){
			cin>>j;
			if(i==k/2)u=j;
			if(i==k/2 +1)p=j;
			int h = k / 2;
			if(i<=h&&j<i-1) flag = 1;
			if(i>h&&j<k-i)flag = 1;	
		}
		if(flag||(u==k/2-1&&p==k/2-1))cout<<"No"<<endl;
		else cout<<"Yes"<<endl;
	}
}
int main(){
	int T;
	cin>>T;
	while(T--){
		solve(); 
	} 
}
