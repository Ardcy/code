#include<bits/stdc++.h>
using namespace std;
const int N = 1e6+1000;
#define int long long
int vis[N],pri[N],mu[N];
int cnt = 0;
void pre(){
	mu[1] = 1;
	for(int i=2;i<N;i++){
		if(!vis[i]){
			pri[cnt++] = i;
			mu[i] = -1;
		}
		for(int j=0;j<cnt && i*pri[j] < N;j++){
			vis[pri[j]*i] = 1;
			if(i%pri[j]==0){
				mu[pri[j]*i] = 0;
				break;
			}else{
				mu[i*pri[j]] = -mu[i];
			}
		}
	}
}


signed main(){
	int t;
	pre();

	cin >> t;
	while(t--){
		int n;
		cin  >> n;
		
		int ans = 0;
		for(int i=1;i<=n;i++){
			ans += (n/i)*(n/i) *(n/i)* mu[i] + 3 * (n/i)*(n/i)*mu[i];
		}
		cout << ans+3  << endl;
	}
}