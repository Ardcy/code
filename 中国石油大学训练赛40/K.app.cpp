#include<bits/stdc++.h>
int a[26]={1,2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97};
int b[101][30];
int c[26];
using namespace std;
int main(){
	for(int i=1;i<=100;i++){
		int u=i;
		for(int j=1;j<=25;j++){
			while(u%a[j]==0&&u!=0)b[i][j]+=1,u/=a[j];
		}
		for(int j=1;j<=25;j++){
			b[i][j]+=b[i-1][j];
		}
		
	}
	for(int i=1;i<=25;i++)cout<<i<<" "<<b[100][i]<<endl;
	int n;
	cin>>n;
	for(int i=1;i<=25;i++)c[i]=b[n][i];
	int ans=0;
	sort(c+1,c+26);
	for(int i=1;i<=25;i++){
		if(c[i]>=74)ans+=1;
	}
	cout<<ans<<endl; 
	for(int i=1;i<=25;i++){
		for(int j=i+1;j<=25;j++){
			for(int k=j+1;k<=25;k++){
				if(c[i]>=2&&c[j]>=4&&c[k]>=4)ans+=1;
			}
		}
	}
	cout<<ans<<endl; 
	for(int i=1;i<=25;i++){
		if(c[i]>=24)
		for(int j=1;j<=i;j++){
			if(c[j]>=2&&j!=i)ans+=1;
		}
	}
	cout<<ans<<endl;
	for(int i=1;i<=25;i++){
		if(c[i]>=14&&c[i]<24)
		for(int j=1;j<=i;j++){
			if(c[j]>=4&&j!=i)ans+=1;
		}
	}
	cout<<ans<<endl;
	
} 
