#include<bits/stdc++.h>
using namespace std;
int a[205000];
int main(){
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int ans1=1,ans2=0;
	for(int i=1;i<n;i++){
		if(a[i+1]<=a[i]*2)ans1++;
		else{
			ans2 = max(ans2,ans1);
			ans1 = 1;
		}
	}
	cout<<max(ans2,ans1)<<endl;
}
