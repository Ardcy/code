#include<bits/stdc++.h>
using namespace std;
const long long mod = 1e9+7;
long long arr[40];
pair<pair<long long,long long>,long long> dp[30][10][10][2];// 平方和
long long qp10[30];
pair<pair<long long,long long>,long long> dfs(long long pos,long long presum,long long pre,bool seven,bool limit){
	if(pos == -1){
		bool flag = (seven==1)||(presum==0)||(pre==0);
		flag = flag;
		if(!flag){
			pair<pair<long long,long long>,long long> p;
			p.first.second = 0;
			p.first.first  = 0;
			p.second = 0;
			return p;
		}
		pair<pair<long long,long long>,long long> p;
		p.first.second = 0;
		p.first.first  = 1;
		p.second = 0;
		return p;
	}
	if(!limit&&dp[pos][presum][pre][seven].second>=0){
		return dp[pos][presum][pre][seven];
	}
	long long up = limit?arr[pos]:9;
	long long ans1 = 0, ans2 = 0,ans3 = 0;
	pair<pair<long long,long long>,long long> p;
	for(long long i=0;i<=up;i++){
		p = dfs(pos-1,(presum*10+i)%7,(pre+i)%7,seven||i==7,i==up&&limit);
		long long sum = p.second,ji = p.first.second;
		long long num = p.first.first;
		if(p.first.first>0){
			ans1 += (qp10[pos]%mod*i)%mod*(qp10[pos]%mod*i%mod)%mod*num%mod + 2*sum%mod*qp10[pos]%mod*i%mod + ji;
			ans2 += num * (qp10[pos]*i) %mod + sum;
			ans3 += num;
		}
		ans1%=mod;ans2%=mod;ans3%=mod;
		ans1+=mod;ans2+=mod;ans3+=mod;
		ans1%=mod;ans2%=mod;ans3%=mod;
	}
	p.first.second = ans1;p.first.first = ans3;p.second = ans2;
	if(!limit){
		dp[pos][presum][pre][seven] = p;
	}
	return p;
}
long long qp(long long a,long long b){
	long long ans = 1;
	while(b){
		if(b&1)ans*=a,ans%=mod;
		a*=a,a%=mod;
		b>>=1;
	}
	return ans;
}
long long solve(long long x){
	long long cnt = 0;long long p = x%mod;long long p1 = x/mod;
	while(x){
		arr[cnt++] = x%10;
		x/=10;
	}
	pair<pair<long long,long long>,long long> ans = dfs(cnt-1,0,0,0,1);
	long long ans1 = (__int128)p*(p+1)*(2*p+1)/6 % mod;
	p = mod-1 ;
	ans1 += p1 * ((__int128)p*(p+1)*(2*p+1)/6%mod)%mod ;
	return ((ans1 - ans.first.second)%mod+mod)%mod; 
}

signed main(){
	qp10[0] = 1;
	for(long long i=1;i<=30;i++){
		qp10[i] = qp10[i-1] * 10 % mod;
	}
	for(long long i=0;i<=29;i++)for(long long j=0;j<10;j++)for(long long k=0;k<10;k++)for(long long w=0;w<2;w++)dp[i][j][k][w].second = -1;
	long long t;
	cin >> t;
	while(t--){
		long long l,r;
		cin >> l >> r;
		cout << ((solve(r) - solve(l-1))%mod+mod)%mod << endl;
	}	 
}


