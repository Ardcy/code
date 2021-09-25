#include<bits/stdc++.h>
using namespace std;
#define int __int128
int a[64];
signed main(){
	a[0]=1;
	for(int i=1;i<=62;i++){
		a[i]=a[i-1]*2;
	}
	long long n;
	cin>>n;
	vector<int>v;
	for(int i=0;i<=62;i++){
		//cout<<(long long)i<<endl;
		int l=1,r=5e9;
		int mid;
		int ans;
		while(l<r){
			//cout<<(long long)l<<endl;
			mid = (l+r)/2;
			ans = (a[i]-1)*mid + (mid*mid-mid)/2;
			if(ans<n)l=mid+1;
			else r=mid;
		}
		mid = (l+r)/2;
		ans = (a[i]-1)*mid + (mid*mid-mid)/2;
		//if(ans==n)cout<<(long long)l<<" "<<(long long)mid<<endl; 
		if(ans==n&&l%2)v.push_back(l*a[i]);
	}
	if(v.size()==0){
		cout<<-1<<endl;
		return 0;
	}
	sort(v.begin(),v.end());
	v.erase(unique(v.begin(),v.end()),v.end());
	for(auto p:v)cout<<(long long)p<<endl;
	return 0;
}
