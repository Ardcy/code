#include<iostream>
using namespace std;
long long A,B,n,k,ans,x;
int main(){
	cin>>n>>k>>A>>B;
	while(true){
		x=n/k*k;
		ans+=(n-x)*A;
		n=x;
		if((n-n/k)*A<=B) 
		break;
		n/=k;
		ans+=B;
	}
	cout<<ans+(n-1)*A;
}
