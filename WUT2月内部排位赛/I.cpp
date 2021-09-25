#include<bits/stdc++.h>
#define debug(x) cerr<<#x<<"="<<x<<endl
using namespace std;
#define int long long
int a[105000];
int b[105000];
int c[105000];
priority_queue<int,vector<int>,greater<int> >q;
signed main(){
	int n;	
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}
	sort(c+1,c+n+1);
	int num1 = 0,num2=0,cnt=0;
	q.push(c[n]);
	for(int i=n-1;i>=1;i--){
		
		if(c[i]*2>=q.top())q.pop(),cnt++;
		else q.push(c[i]);
	}
	cout<<n-cnt<<endl;
	return 0;
}
