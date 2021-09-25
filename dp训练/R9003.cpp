#include<bits/stdc++.h>
using namespace std;
int main(){
	int a,b;
	cin>>a>>b;
	if(b>a-2){
		cout<<b<<endl;
		return 0;
	}
	cout<<(b-1)+((a-b)+1)*(a-b)/2<<endl;
}
