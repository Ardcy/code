#include<bits/stdc++.h>
using namespace std;
int a[1050];
int main(){
	int n;
	cin>>n;
	int i;
	for(i=1;;i++){
		if(n>=i)a[i]=i,n-=i;
		else break;
	}
	i--;
	cout<<i<<endl;
	for(int j=1;j<i;j++){
		cout<<a[j]<<" ";
	}
	cout<<a[i]+n<<endl;
}
