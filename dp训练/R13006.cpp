#include<bits/stdc++.h>
using namespace std;
int a[100];
int main(){
	int n;
	cin>>n;
	int d;
	for(int i=1;i<=n;i++){
		cin>>d;
		if(d==4)a[d]++;
		if(d==8&&a[4])a[4]--,a[d]++;
		if(d==15&&a[8])a[8]--,a[d]++;
		if(d==16&&a[15])a[15]--,a[d]++;
		if(d==23&&a[16])a[16]--,a[d]++;
		if(d==42&&a[23])a[23]--,a[d]++;
	}

	cout<<n-6*a[42]<<endl;
	
}
