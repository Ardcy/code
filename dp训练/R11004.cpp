#include<bits/stdc++.h>
using namespace std;
int coutt(int n){
	int ans = 0;
	while(n>=10){
		ans+=n%10;
		n/=10;
	}
	return n+ans==10;
}
int main(){
	int n;
	cin>>n;
	int cnt =0;
	for(int i=1;i<=10800100;i++){
		if(coutt(i)==1)cnt++;
		if(cnt==n){
			cout<<i<<endl;
			return 0;
		}
	}
}
