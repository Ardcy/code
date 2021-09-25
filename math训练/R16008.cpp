#include<bits/stdc++.h>
using namespace std;
#define int long long
int ep = 1e-6;
double a[205000];
int b[205000];
signed main(){
	int n;
	//cout<<(int)(-2.3)<<endl;
	cin>>n;
	double u;
	int cnt = 0;
	int sum = 0;
	for(int i=1;i<=n;i++){
		cin>>u;
		a[i]=u;
		if(u-floor(u)>ep){
			cnt++;		
		}
		sum+=floor(u);
	}
	for(int i=1;i<=n;i++){
		if(sum!=0&&cnt>0&&a[i]-floor(a[i])>ep){
			cnt--;
			cout<<floor(a[i])+1<<endl;
			sum++;
		}
		else {
			cout<<floor(a[i])<<endl;
		}
	}
	
}
