#include<bits/stdc++.h>
using namespace std;
int c[2]={0,1};
int main()
{
	int n,cnt=0,k,t;
	int s[3000]={0};
	cin>>n;
	if(n==0){cout<<"0"<<endl;return 0;}
	while(n!=0)
	{
		k=n%(-2);
		t=n/(-2);
		if(k<0){k=k+2;t++;}	
		n=t;
		s[++cnt]=k;	
	}
	for(int i=cnt;i>=1;i--)
		cout<<s[i]; 
	return 0; 
}

