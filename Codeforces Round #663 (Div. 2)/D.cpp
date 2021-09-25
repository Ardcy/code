#include<bits/stdc++.h>
using namespace std;
#define int long long
#define fi first
#define se second
#define inf INT_MAX
#define mp make_pair
#define pb push_back
const int mod = 998244353;
const int N = 200500;
int qp(int a,int b){int ans=1;while(b){if(b&1)ans*=a,ans%=mod;a*=a,a%=mod;b>>=1;}return ans;};
int inv[N],fac[N],rev[N];
void init(int n){
	fac[0]=1;rev[n]=1;
	for(int i=1;i<=n;i++)fac[i]=fac[i-1]*i%mod;
	rev[n]=qp(fac[n],mod-2);
	for(int i=n-1;i>=0;i--)rev[i]=rev[i+1]*(i+1)%mod;
	for(int i=1;i<n;i++)inv[i]=(rev[i]*fac[i-1]%mod)%mod;
}
string s;
char A[5][505000];
int dp[505000];

//char ans1[4][405000];
//char ans2[4][405000];
//char ans3[4][405000];
//char ans4[4][405000];
char mode1[]= "0010";
char mode2[]="0101";

char mode3[]="0111";
char mode4[]="0000";

char mode5[]="0011";
char mode6[]="0100";

char mode7[]="0110";
char mode8[]="0001";

signed main(){

	int n,m;
	cin>>n>>m;
	if(n>=4){
		for(int i=1;i<=n;i++)cin>>s;
		cout<<-1<<endl;
	}else{
		if(n==1){
			cin>>s;
			cout<<0<<endl;
				
		}
		else if(n==2){
			for(int i=1;i<=n;i++)scanf("%s",A[i]+1);
			for(int i=1;i<=m;i++){
				for(int j=1;j<=n;j++){
					if(A[j][i]=='1')dp[i]+=1;
				}
			}
			int ans1 = 0;
			int ans2 = 0;
			for(int i=1;i<=m;i++){
				
				if(i&1){
					ans1+=(dp[i]&1);
					ans2+=!(dp[i]&1);
				}else{
					ans1+=!(dp[i]&1);
					ans2+=(dp[i]&1);
				}
			}
			cout<<min(ans1,ans2)<<endl;
		}else if(n==3){
			for(int i=1;i<=n;i++)scanf("%s",A[i]+1);
			
		

			
			//case 1 
		    int ans_case1 = 0;
			for(int i=1;i<=m;i++){
				
				if(i&1){
					
					int a1 = 0, a2 = 0;
					for(int j=1;j<=3;j++){
						if(A[j][i]!=mode1[j]){
							a1++;
						}
						if(A[j][i]!=mode2[j]){
							a2++;
						}
					}
					ans_case1 +=min(a1,a2);
					
					
				}else{
					
					int a1 = 0, a2 = 0;
					for(int j=1;j<=3;j++){
						if(A[j][i]!=mode3[j]){
							a1++;
						}
						if(A[j][i]!=mode4[j]){
							a2++;
						}
					}
					ans_case1 +=min(a1,a2);
				}
			}
			
			//case2
			
		    int ans_case2 = 0;
			for(int i=1;i<=m;i++){
				
				if(i&1){
					
					int a1 = 0, a2 = 0;
					for(int j=1;j<=3;j++){
						if(A[j][i]!=mode3[j]){
							a1++;
						}
						if(A[j][i]!=mode4[j]){
							a2++;
						}
					}
					ans_case2 +=min(a1,a2);
					
					
				}else{
					
					int a1 = 0, a2 = 0;
					for(int j=1;j<=3;j++){
						if(A[j][i]!=mode1[j]){
							a1++;
						}
						if(A[j][i]!=mode2[j]){
							a2++;
						}
					}
					ans_case2 +=min(a1,a2);
				}
			}
			
			//case3
			
		    int ans_case3 = 0;
			for(int i=1;i<=m;i++){
				
				if(i&1){
					
					int a1 = 0, a2 = 0;
					for(int j=1;j<=3;j++){
						if(A[j][i]!=mode5[j]){
							a1++;
						}
						if(A[j][i]!=mode6[j]){
							a2++;
						}
					}
					ans_case3 +=min(a1,a2);
					
					
				}else{
					
					int a1 = 0, a2 = 0;
					for(int j=1;j<=3;j++){
						if(A[j][i]!=mode7[j]){
							a1++;
						}
						if(A[j][i]!=mode8[j]){
							a2++;
						}
					}
					ans_case3 +=min(a1,a2);
				}
			}

			//case3
			
		    int ans_case4 = 0;
			for(int i=1;i<=m;i++){
				
				if(i&1){
					
					int a1 = 0, a2 = 0;
					for(int j=1;j<=3;j++){
						if(A[j][i]!=mode7[j]){
							a1++;
						}
						if(A[j][i]!=mode8[j]){
							a2++;
						}
					}
					ans_case4 +=min(a1,a2);
					
					
				}else{
					
					int a1 = 0, a2 = 0;
					for(int j=1;j<=3;j++){
						if(A[j][i]!=mode5[j]){
							a1++;
						}
						if(A[j][i]!=mode6[j]){
							a2++;
						}
					}
					ans_case4 +=min(a1,a2);
				}
			}
			
			
			int ans = 0;
			ans = min({ans_case1,ans_case2,ans_case3,ans_case4});
			cout<<ans<<endl;
		}
	}
	return 0;
}


