#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e5+5;
int arr[N+5];
char a[200][200];
#define pb push_back
int dx[] = {0,0,1,0,1};
int dy[] = {0,0,0,1,1};
int cnt1 = 0;
vector<int>Ans[1000500];
void solve(int x,int y) {

	int cnt = 0;
	int flag1 = 0 , flag2 = 0;
	for(int i=1; i<=4; i++) {
		if(a[x+dx[i]][y+dy[i]]=='1') {
			cnt++;
			flag1+=dx[i];
			flag2+=dy[i];
		}
	}

	//cout<<"cnt = "<<cnt<<endl;


	if(cnt == 4) {
		for(int i=1; i<=4; i++) {
			//cout<<x+dx[i]<<" "<<y+dy[i]<<" ";

			cnt1++;
			for(int j=1; j<=4; j++) {
				if(dx[j]!=dx[i]||dy[j]!=dy[i]) {
					Ans[cnt1].pb(x+dx[j]);
					Ans[cnt1].pb(y+dy[j]);
				}
			}

		}
		//cout<<endl;
	} else if(cnt == 3) {
		for(int i=1; i<=4; i++) {
			if(a[x+dx[i]][y+dy[i]]=='0') {
				//cout<<x+1-dx[i]<<" "<<y+1-dy[i]<<endl;

				cnt1++;
				for(int j=1; j<=4; j++) {
					if(dx[j]!=dx[i]||dy[j]!=dy[i]) {
						Ans[cnt1].pb(x+dx[j]);
						Ans[cnt1].pb(y+dy[j]);
					}
				}
			}
		}
	} else if(cnt == 2) {
		for(int i=1; i<=4; i++) {
			if(a[x+dx[i]][y+dy[i]]=='1' && (flag1+flag2)%2==0) {
				//cout<<x+dx[i]<<" "<<y+dy[i]<<" ";

				cnt1++;
				for(int j=1; j<=4; j++) {
					if(dx[j]!=dx[i]||dy[j]!=dy[i]) {
						Ans[cnt1].pb(x+dx[j]);
						Ans[cnt1].pb(y+dy[j]);
					}
				}

			} else if(a[x+dx[i]][y+dy[i]]=='1' && (flag1+flag2)%2==1) {
				//cout<<x+1-dx[i]<<" "<<y+1-dy[i]<<" ";
				cnt1++;
				for(int j=1; j<=4; j++) {
					if(dx[j]!=dx[i]||dy[j]!=dy[i]) {
						Ans[cnt1].pb(x+dx[j]);
						Ans[cnt1].pb(y+dy[j]);
					}
				}
			}
		}
		//	cout<<endl;
	} else if(cnt==1) {
		for(int i=1; i<=4; i++) {
			if(a[x+dx[i]][y+dy[i]]=='0') {
				//cout<<x+dx[i]<<" "<<y+dy[i]<<" ";
				cnt1++;
				for(int j=1; j<=4; j++) {
					if(dx[j]!=dx[i]||dy[j]!=dy[i]) {
						Ans[cnt1].pb(x+dx[j]);
						Ans[cnt1].pb(y+dy[j]);
					}
				}
			}
		}
		//	cout<<endl;
	}
	for(int i=1; i<=4; i++) {
		a[x+dx[i]][y+dy[i]]='0';
	}
}


signed main() {
	int t;
	cin>>t;
	while(t--) {
		int n,m;
		cin>>n>>m;
		for(int i=1; i<=n+2; i++) {
			for(int j=1; j<=m+2; j++) {
				a[i][j]='0';

			}
		}
		getchar();
		for(int i=1; i<=n; i++) {
			for(int j=1; j<=m; j++) {
				a[i][j]=getchar();

			}
			getchar();
		}






		//cout<<(n+(n&1))*(m+(m&1))<<endl;

		for(int i=0; i<(n+(n&1))*(m+(m&1)); i++) {
			Ans[i].clear();
		}
		cnt1 = 0;



		if((n&1)&&(m&1)) {

			for(int i=1; i<=n-2; i++) {

				if(a[i][m]=='1') {
					cnt1++;
					Ans[cnt1].pb(i);
					Ans[cnt1].pb(m);
					Ans[cnt1].pb(i+1);
					Ans[cnt1].pb(m);
					Ans[cnt1].pb(i);
					Ans[cnt1].pb(m-1);

					a[i][m]  ='0'+('1'-a[i][m]);
					a[i+1][m]='0'+('1'-a[i+1][m]);
					a[i][m-1]='0'+('1'-a[i][m-1]);
				}

			}
			for(int i=1; i<=m-2; i++) {

				if(a[n][i]=='1') {
					cnt1++;
					Ans[cnt1].pb(n);
					Ans[cnt1].pb(i+1);
					Ans[cnt1].pb(n);
					Ans[cnt1].pb(i);
					Ans[cnt1].pb(n-1);
					Ans[cnt1].pb(i+1);

					a[n][i+1] = '0'+('1'-a[n][i+1]);
					a[n][i] = '0'+('1'-a[n][i]);
					a[n-1][i+1] = '0'+('1'-a[n-1][i+1]);
				}
			}
			n-=1;
			m-=1;
			solve(n,m);
		}

		if((n&1)&&(m%2==0)) {
			for(int i=1; i<m; i++) {
				if(a[n][i]=='1') {

					cnt1++;
					Ans[cnt1].pb(n-1);
					Ans[cnt1].pb(i);
					Ans[cnt1].pb(n);
					Ans[cnt1].pb(i);
					Ans[cnt1].pb(n-1);
					Ans[cnt1].pb(i+1);

					a[n-1][i] = '0'+('1'-a[n-1][i]);
					a[n][i] = '0'+('1'-a[n][i]);
					a[n-1][i+1] = '0'+('1'-a[n-1][i+1]);
				}
			}
			if(a[n][m]=='1') {
				cnt1++;
				Ans[cnt1].pb(n);
				Ans[cnt1].pb(m);
				Ans[cnt1].pb(n-1);
				Ans[cnt1].pb(m);
				Ans[cnt1].pb(n-1);
				Ans[cnt1].pb(m-1);

				a[n][m] = '0'+('1'-a[n][m]);
				a[n-1][m] = '0'+('1'-a[n-1][m]);
				a[n-1][m-1] = '0'+('1'-a[n-1][m-1]);

			}


		}
		if((m&1)&&(n%2==0)) {

			for(int i=1; i<n; i++) {
				if(a[i][m]=='1') {

					cnt1++;
					Ans[cnt1].pb(i);
					Ans[cnt1].pb(m-1);
					Ans[cnt1].pb(i);
					Ans[cnt1].pb(m);
					Ans[cnt1].pb(i+1);
					Ans[cnt1].pb(m-1);

					a[i][m-1] = '0'+('1'-a[i][m-1]);
					a[i][m] = '0'+('1'-a[i][m]);
					a[i+1][m-1] = '0'+('1'-a[i+1][m-1]);
				}
			}
			if(a[n][m]=='1') {
				cnt1++;
				Ans[cnt1].pb(n);
				Ans[cnt1].pb(m);
				Ans[cnt1].pb(n);
				Ans[cnt1].pb(m-1);
				Ans[cnt1].pb(n-1);
				Ans[cnt1].pb(m-1);

				a[n][m] = '0'+('1'-a[n][m]);
				a[n][m-1] = '0'+('1'-a[n][m-1]);
				a[n-1][m-1] = '0'+('1'-a[n-1][m-1]);

			}

		}

		for(int i=1; i<=n; i+=2) {
			if(i==n)i-=1;
			for(int j=1; j<=m; j+=2) {
				if(j==m)j-=1;
				solve(i,j);
			}
		}
		cout<<cnt1<<endl;
		for(int i=1; i<=cnt1; i++) {
			for(auto p:Ans[i]) {
				cout<<p<<" ";
			}
			cout<<endl;
		}

	}

	return 0;
}
