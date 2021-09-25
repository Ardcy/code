#include<bits/stdc++.h>
using namespace std;
#define int long long
int m,L;
int arr[300];
int brr[300];
int fun(int x){
	int ans = 0;
	while(x){
		if(x&1)ans+=1;
		x>>=1;
	}
	return ans%2;
}
int ans;

int cal(int p,int L){
	if(L%256>p+m-1){
		return L/256;
	}else{
		return L/256 - 1;
	}

}
void solve(){
	ans = 0;
	scanf("%lld%lld",&m,&L);
	for(int i=0;i<m;i++){
		scanf("%lld",&arr[i]);
	}
	// 如何解决这个问题
	// 首先 解决 0-L 中 有多少个 最终满足条件的 +100 最多影响 到 256  
	// 256 - m
	//  
	int flag = 1;  
	for(int i=0;i<= 256-m;i++){
		flag = 1;
		// 255-m 中 奇偶性一致
		for(int j=0;j<=m-1;j++){
			if(brr[j] != arr[j])
			{
				flag = 0;break;
			}
		}
		if(flag){
			ans += cal(i,L);
		}
		int flag = 1;
		// 255-m 中 奇偶性相反
		for(int j=0;j<=m-1;j++){
			if(brr[j] == arr[j])
			{
				flag = 0;break;
			}

		}
		if(flag){
			ans += cal(i,L);
		} 


		
	}
	cout << ans << endl;
}

signed main(){

	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	int T;
	for(int i=1;i<=255;i++){
		brr[i] = fun(i);
	}
	cin >> T;
	while(T--){
		solve();
	}
}