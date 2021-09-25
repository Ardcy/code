#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;
const int N = 105;
ll m,a[N],n;
ll L;
#define int long long
void solve(){
	
	// m 表示 匹配段长度
	// L 表示 计算的范围
	scanf("%llu%llu",&m,&L);

	
	n = 0;
	
	// n 表示需要计算的位数
	for(int i=L;i;i>>=1)n++;

	// 读入
	for(int i=0;i<m;i++){
		scanf("%llu",&a[i]);
	}


	ll z=1,lg=0;
	
	// 匹配段的位数
	for(;z<=m;z<<=1)lg++;

	// 如果 L 很小 暴力计算
	if(z>=L){
		ll ans=0;
		for(int i=0;i<=L;i++){
			bool ok = 1;
			for(int j=0;j<m;j++){
				if(__builtin_parityll(i+j)!=a[j]){
					ok = 0;break;
				}
			}
			ans+=ok;

		}
		printf("%llu\n",ans);
		return;
	}

	// 如果 L 较大

	ll ans = 0;

	// z 是 位数 比如 m = 156 z = 128
	// ans 把每个都计算 出来 
	
	for(int x = 0;x<z;x++){
		bool ok = 1,fir = 0;

		// 是否可能满足 
		// 
		int par = 0,opl = 0,ts = a[0]^__builtin_parityll(x);
		

		for(int j=1;j<m;j++){
			int tmp = __builtin_parityll(x+j);
			if(x+j>=z&&!fir){
				fir = 1;
				opl = a[j]^ts^tmp;
			}
			if((tmp^opl)!=(a[j]^ts)){
				ok = 0;
				break;
			}
		}
		if(!ok){
			continue;
		}

		// 计算 数值 
		// 
		for(int i=n;i>=lg;i--){
			if(!fir||((i-lg)&1)==opl){
				int tmp = (((1ll<<(i-lg))-1)<<lg)+x;
				if(tmp>L)continue;
				tmp = (L-tmp) >> (i+1);
				ans += (tmp+1)>>1;
				if(!(tmp&1)&&__builtin_parityll(tmp)==(ts^((i-lg)&1)))ans++;

			}
		}
	}
	cout<<ans<<endl;
}
signed main(){
	int t;
	cin >> t;
	while(t--){
		solve();
	}
}