#include<bits/stdc++.h>
using namespace std;
int a[120];
int main(){
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int f=0;
	for(int i=1;i<=n;i++){
		if(a[i]%2==0){
			if(a[i]%3==0||a[i]%5==0){
				
			}
			else f=1;
		}
	}
	
	if(!f)cout<<"APPROVED"<<endl;
	else cout<<"DENIED"<<endl;
}
