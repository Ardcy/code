#include<bits/stdc++.h>
using namespace std;
const int N = 1e6+100000;
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
	int kcase = 1;
	while(t--){
		int a,b,c,d,k;
		cin >> a >> b >> c >> d >> k;
		int ans = 0;
		if(k==0){
			cout << "Case "<<kcase++ << ": " << ans << endl;
			continue;
		}
		if(b > d)swap(b,d);
		d/=k,b/=k;
		for(int i = 1;i <= min(b,d); i++){
			int b1 = b/i;
			int b2 = d/i;
			if((2*b2+1-b1)*b1 <= 0)continue;
			ans += mu[i] * (2*b2+1-b1)*b1/2;
		}
		cout << "Case "<<kcase++ << ": " << ans << endl;
	}
}