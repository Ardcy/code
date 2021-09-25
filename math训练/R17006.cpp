#include<bits/stdc++.h>
using namespace std;
double a[5000];
#define int long long
signed main(){
	int n;
	cin>>n;
	double sum = 0;
	for(int i=1;i<=2*n;i++){
		cin>>a[i];
		sum+=a[i]-floor(a[i]);	
	}
	int cnt = 0;
	for(int i=1;i<=2*n;i++){
		if(a[i]-floor(a[i])<1e-7)cnt++;
	}
	int ma = n;
	int l=0,r=0;
	
	if(cnt>ma)l=0,r=2*n-cnt;
	else r=ma,l=ma-cnt;
//	cout<<sum<<" "<<l<<" "<<r<<endl;

	if(sum>r){
		printf("%.3f\n",sum-r*1.0);
	}
	
	else if(sum<l){
		printf("%.3f\n",l*1.0-sum);
	}
	else{
		printf("%.3f\n",min(sum-floor(sum),1.0-sum+floor(sum)));
	}
	
	return 0;
}
