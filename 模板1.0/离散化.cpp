#include<bits/stdc++.h>
#define debug(x) cerr<<#x<<"="<<x<<endl
#define int long long
using namespace std;
int a[6]={0,11,11,5,7,9};
int res[5],cnt,cp[6];
void discretization(int a[],int n){
	for(int i=0;i<=n;i++)cp[i]=a[i];
	sort(a+1,a+n+1);
	cnt = unique(a+1,a+n+1)-(a+1);
	for(int i=1;i<=n;i++)
	res[i]=lower_bound(a+1,a+cnt+1,cp[i])-a;
}
signed main(){
	discretization(a,5);
	for(int i=1;i<=5;i++)cout<<res[i]<<" ";
}
