#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define inf INT_MAX
#define mp make_pair
#define pb push_back
const int mod = 998244353;
int qp(int a,int b){int ans=1;while(b){if(b&1)ans*=a,ans%=mod;a*=a,a%=mod;b>>=1;}return ans;};
int T,d;
ll l,r;
int cnt[11];
ll dp[11][22],C[22][22];
int a[22]; 


ll dfs(int pos,int limit,int lead){
	// ����������һλ ,�ж�d�Ƿ��ǳ������ε�һλ 
	if(pos==-1){
		int mx = 0,num = 0;
		for(int i=0;i<=9;i++)if(cnt[i]>cnt[mx])mx=i;
		for(int i=0;i<=9;i++)if(cnt[i]==cnt[mx])num++;
		return mx==d&&num==1;
	}
	
	// ����������ҷ�ǰ��0 
	if(!limit&&!lead){
		ll ans = 0;
		int mx = cnt[d];
		// ֮ǰ�Ѿ����ֹ�����Ҫ�滮�����ָ���
		for(int i=0;i<=9;i++)if(i!=d)mx=max(mx,cnt[i]+1);
		// mx��ʾ��С�� dҪ���ֵĴ���
		// Ӧ�����������־���1
		// �õ����������ָ�����1��ֵ 
		// ��ʱ�Ѿ������ƣ�����ǰ��0������֪�������Ѿ����ֹ��Ĵ��� 
		//Ŀ������� ʹ��d�������εĿ���
		// pos+1 ��ʾ�����༸��λ��
		// cnt[d] ��ʾ ��d�Ѿ����ֹ����ٴ�
		// num ��ʾ�ý���� d���ܳ��ֵĴ��� 
		// ö������d���ܳ��ֵĴ��� 
		for(int num = mx;num<=cnt[d]+pos+1;num++){
			memset(dp,0,sizeof(dp));
			dp[0][0]=1;
			// i��ʾ��
			for(int i=1;i<=10;i++){
				// ���i������ Ŀ������ 
				if(i==d+1){
					for(int j=0;j<=20;j++){
						dp[i][j]=dp[i-1][j];
						
					}continue; 
				}
				// ������Ŀ������  
                // j�ķ�Χ��Ӧnum�ķ�Χ
				// ����һ�����Ӷ�			
				// �ص� ----  dp
				// dp[i][j] ��ʾǰiλ����ָ������һλ���Ѿ���ʣ���λ�ð�����j����
				// �ص� ǰiλ ���������� 
				// cnt[d]+pos+1-num ö�ٺ��ʣ��λ�ø���
				// num - cnt[i-1] - 1 ��ʾ ���� i ���ܳ��ֵ�������  
				// j-k > 0 ��֤�� ����i�� �¼��������ᳬ��ʣ��λ�ø��� 
				// dp[i][j]�ļ��㷽ʽ
				// ʣ����  cnt[d]+pos+1-num ��λ�õ������
				// ����֪�� ǰ��λ���ַŵ� 10��λ���е��������
				// ǰx+1λ �ŵ� 10��λ���е������
				// pos+1-j+k ��ʾ ��λ - ��λ�е��Ѿ�ռ�е�λ�� + ����i�����Ĵ���
				// ��ͬ�� ʵ�ʿ�λ ʵ�ʿ�λ��ѡ��  k ��λ�� ���� i�ķ����� 
				for(int j=0;j<=cnt[d]+pos+1-num;j++){
					for(int k=0;k<=num-cnt[i-1]-1&&j-k>=0;k++){
						dp[i][j]+=dp[i-1][j-k]*C[pos+1-j+k][k];
					}	
				}
			}
			//ÿ��ö��֮�����һ���� 
			ans += dp[10][cnt[d]+pos+1-num];
			// dp[10][cnt[d]+pos+1-num] ��ʾ 10λȫ���ź�� ����λ�ö��ź����� �Ŀ����� 
					
		} 
		return ans;
	}
	int up = limit?a[pos]:9;
	ll ans = 0;
	
	for(int i=0;i<=up;i++){
		
		// ���Ӷȹ��ƣ�
		// �����Ż�������¸��Ӷ�Ϊ 9��18�Ρ�
		// ���Ż����Ӷ�Ϊ O(����)*O���������λ����*O��dp��
		 
		if(!lead||i!=0)cnt[i]++;
		// �ȼ��� ǰ��0��i=0�Ų��䣬����������ı�
		// ǰ��0�ս���ɷ�ǰ��0
		// �����ǰ��0 ���� ��λѡ������ֲ���0 ��ôcnt[i]++; 
		// ����˵��
		// ���1235
		// ö��0��ʱ�������ǰ��0��lead=true,��ǰλҲ����ǰ��0����
		// �����1023 ö�ٵڶ�λ��0��lead=false,��ô��һλӦ��������
		ans+=dfs(pos-1,limit&&i==a[pos],lead&&i==0);
		// ���limit��true
		// �ҵ�ǰѡ��λ�������������
		// ��������limit
		// �����ǰ�����ƣ����һλ�ض�Ҳ������
		// ǰ��0����һλ��ǰ��0������������ ��һλ��ǰ��0����һλ������0��
		if(!lead||i!=0)cnt[i]--;
		
		// ״̬��ԭ 
	}
	return ans;
}
ll solve(ll x){
	int len = 0;
	while(x){
		a[len++]=x%10;x/=10;
	}
	return dfs(len-1,true,true);
}
int main(){
	C[0][0]=1;
	for(int i=1;i<=20;i++){
		C[i][0]=1;
		for(int j=1;j<=i;j++){
			C[i][j]=C[i-1][j]+C[i-1][j-1];
		}
	}
	scanf("%d",&T);
	while(T--){
		scanf("%lld%lld%d",&l,&r,&d);
		printf("%lld\n",solve(r)-solve(l-1));
	}
	return 0;
}
