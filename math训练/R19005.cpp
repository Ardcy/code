#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[105000];
int b[105000];
signed main(){
	int n;
	cin>>n;
	int sum=0;
	for(int i=1;i<=n;i++)cin>>a[i],sum+=a[i];
	b[n]=1,b[n-1]=-1;
	int temp = 1;
	int f = a[n]-a[n-1];
	for(int i=n-2;i>=1;i--){
		if(f<a[i]){
			if(temp==1)b[i]=-1;else b[i]=1;
			temp=-temp;
		}
		else{
			if(temp==-1)b[i]=1;else b[i]=-1;
		}
		f=abs(f-a[i]);
	}
	sum=0;
	for(int i=1;i<=n;i++){
		sum+=a[i]*b[i];
	}
	//cout<<sum<<endl;
	if(sum==0)sum+=1;
	for(int i=1;i<=n;i++){
		if(sum*b[i]>0)cout<<"+";else cout<<"-";
	}
	cout<<endl;
	return 0;
}
