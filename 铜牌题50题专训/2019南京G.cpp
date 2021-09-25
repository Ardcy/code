#include<bits/stdc++.h>
using namespace std;
int mod = 1e9+7;
#define int long long 
struct mat{
	int x[5][5];
	mat(){
		memset(x,0,sizeof(x));
		for(int i=1;i<=4;i++)x[i][i] = 1;
	}	
	mat operator * (const mat&b)const {
		mat c;
		for(int i=1;i<=4;i++){
			for(int j=1;j<=4;j++){
				c.x[i][j] = 0;
			}
		}
		for(int i=1;i<=4;i++){
			for(int j=1;j<=4;j++){
				for(int k=1;k<=4;k++){
					c.x[i][j] += x[i][k] * b.x[k][j];
					c.x[i][j] %= mod;
				}
			}
		}
		return c;	
	}
};
mat qp(mat a,int b){
	mat ans;
	while(b){
		if(b&1) ans = ans *  a;
		a = a*a;
		b >>= 1;
	}
	return ans;
}


signed main(){
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		int ans = n*(n+1)*(n+2)*(n+3) / 24;
		cout << ans << endl;
	} 
}
