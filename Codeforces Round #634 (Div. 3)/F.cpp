#include<bits/stdc++.h>
using namespace std;
#define int long long
#define fi first
#define se second
#define inf INT_MAX
#define mp make_pair

char A[150][150][150];
int vis[150][150][150];

int a[][3]={
1,0,0
0,1,0
0,0,1
-1,0,0
0,-1,0
0,0,-1};

signed main(){
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			for(int k=1;k<=n;k++){
				cin>>A[i][j];
			}
		}
	}
	
	return 0;
}


