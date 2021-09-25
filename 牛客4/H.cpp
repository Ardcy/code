#include<bits/stdc++.h>
using namespace std;
const int N = 1e6+5;
int arr[3][3][N];
int brr[3][3];
void solve(){
	int n,m;
	string s;
	string t;
	cin >> n >> m;
	
	for(int i=0;i<3;i++)for(int k=0;k<3;k++)for(int j=0;j<=n+m;j++)arr[k][i][j] = 0;
	
	cin >> s >> t;for(int i=1;i<=m;i++)s+='I';
	n = n + m;

	for(int i=0;i<3;i++){
		for(int k=0;k<3;k++)brr[i][k] = 0;
	}
	for(int i=0;i<t.length();i++){
		if(t[i] == 'P')t[i] = 'R';
		else if(t[i] == 'R')t[i] = 'S';
		else if(t[i] == 'S') t[i] = 'P';

		
	}
	for(int i=0;i<3;i++){
		for(int j=0;j<3;j++){
			cout << brr[i][j] << " ";
		}cout << endl;
	}
	

	cout << s << endl;
	cout << t << endl;
	int ans = 0;
	for(int i=0;i<n-m;i++){
		int ans1 = 0;int l = i, r = i+m;

		cout << " i = " << i << endl;
		for(int i1=0;i1<3;i1++){
			for(int j=0;j<3;j++){
				cout << arr[i1][j][r] - arr[i1][j][l] << " ";
			}cout << endl;
		}
		
		for(int j=0;j<3;j++){
			for(int k=0;k<3;k++){
				int u = arr[(k+(i)+0)%3][j][r] - arr[(k+(i)+0)%3][j][l];
				ans1 += min(u,brr[k][j]);
			}
		}
		cout << "ans1 = " << ans1 << endl;
		ans = max(ans,ans1);
	}
	cout << ans << endl;
}
signed main(){
	while(1){
		solve();
	}
	// cout << t << endl;
}