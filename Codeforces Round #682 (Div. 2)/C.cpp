#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e5+5;
int a[200][200];
int b[200][200];
void solve(int n,int m){
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cout<<b[i][j]<<" ";
		}cout<<endl;
	}
}
signed main() {
	int t;
	cin>>t;
	while(t--) {
		int n,m;
		cin>>n>>m;
		for(int i=1; i<=n; i++) {
			for(int j=1; j<=m; j++) {
				cin>>a[i][j];
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				if((a[i][j] %2 )==(i+j)%2){
					cout<<a[i][j]<<" ";
				}
				else{
					cout<<a[i][j]+1<<" ";
				}
			}cout<<endl;
		}


	}

	return 0;
}
