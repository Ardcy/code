#include<bits/stdc++.h>
using namespace std;
int N;
bool isp(int n){
	int a=sqrt(n)+0.5;
	for(int i=2;i<=a;i++)if(n%i==0)return 0;return 1;
}
int main(){
	cin>>N;
	if(isp(N))cout<<1<<"\n"<<N<<endl;
	else {
		cout<<3<<endl;
		cout<<3<<" ";
		int a = N-3;
		for(int i=2;i<=a>>1;i++){
			if(isp(i)&&isp(a-i))return cout<<i<<" "<<a-i<<endl,0;
		}
	}
}
