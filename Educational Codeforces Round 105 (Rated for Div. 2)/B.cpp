#include<bits/stdc++.h>
using namespace std;

int u,r,d,l;
int n;
bool check(int v1,int v2,int v3,int v4){
	u -= (v1+v2);
	r -= (v2+v3);
	d -= (v3+v4);
	l -= (v4+v1);
	if(u <= n-2 && r <= n-2 && d<=n-2 && l <=n-2 && u>=0 && r>=0 && d>=0 && l>=0){
		return true;
	}
	u += (v1+v2);
	r += (v2+v3);
	d += (v3+v4);
	l += (v4+v1);
	return false;
}
signed main(){
	int t;
	cin >> t;
	while(t--){
		int flag = 0;
		cin >> n;
		cin >> u >> r >> d >> l;
		for(int i=0;i<=1;i++)
		for(int j=0;j<=1;j++)
		for(int f=0;f<=1;f++)
		for(int w=0;w<=1;w++)
			if(check(i,j,f,w)){
				flag = 1;
			}


		if(flag){
			cout << "YES" <<endl;
		}else{
			cout << "NO" <<endl;
		}
	}
}