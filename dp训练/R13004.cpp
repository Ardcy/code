#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;
	cin>>n;
	string a,b;
	cin>>a>>b;
	a+="0";
	b+="0";
	int ans=0;
	for(int i=0;i<n;i++){
		if(a[i]!=b[i]){
			if(a[i+1]!=b[i+1]&&a[i]!=a[i+1]){
				ans+=1,i++;
			}
			else ans+=1;
		}
	}
	cout<<ans<<endl;
}
