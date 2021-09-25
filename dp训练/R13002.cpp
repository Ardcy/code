#include<bits/stdc++.h>
using namespace std;
int a[200];
int b[200];
int main(){
	int n,m;
	cin>>n;
	for(int i=1;i<=n;i++){
		int e;
		cin>>e;
		a[e]++;
	}
	cin>>m;
	for(int i=1;i<=m;i++)cin>>b[i];
	sort(b+1,b+m+1);
	int cnt = 0;
	for(int i=1;i<=m;i++){
		if(a[b[i]-1]>0)a[b[i]-1]--,cnt++;
		else if(a[b[i]]>0)a[b[i]]--,cnt++;
		else if(a[b[i]+1]>0)a[b[i]+1]--,cnt++;
	}
	cout<<cnt<<endl;
}
