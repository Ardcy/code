#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,n) for (int i=a;i<n;i++)
#define per(i,a,n) for (int i=n-1;i>=a;i--)
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second
#define SZ(x) ((int)(x).size())
#define int long long
typedef vector<int> VI;
typedef pair<int,int> PII;
typedef double db;
mt19937 mrand(random_device{}());
const int mod = 1000000007;
int rnd(int x){return mrand()%x;}
template <typename T>
vector<int> manacher(int n,const T&s){
	if(n==0){
		return vector<int>();
	}
	vector<int>res(2*n-1,0);
	int l=-1,r=-1;
	for(int z=0;z<2*n-1;z++){
		int i=(z+1)>>1;
		int j=z>>1;
		int p=(i>=r?0:min(r-i,res[2*(l+r)-z]));
		while(j+p+1<n&&i-p-1>=0){
			if(!(s[j+p+1]==s[i-p-1])){
				break;
			}
			p++;
		}
		if(j+p>r){
			l=i-p;r=j+p;
		}
		res[z]=p;
	}
	return res;
}
template <typename T>
vector<int> manacher(const T &s){
	return manacher((int) s.size(),s);
}
int pb(int a,int b) {int res=1;a%=mod;assert(b>=0);for(;b;b>>=1){if(b&1)res=res*a%mod;a*=a;a%=mod;}return res;}
signed main(){
	int t;
	cin>>t;
	string t1;
	while(t--){
		string s;
		cin>>s;
		int k = 0;
		int l = s.length();
		for(int i=0;i<s.length();i++){
			if(s[i]==s[l-1-i]&&i<(l-1-i))k++;
			else break;
		}
		if(2*k>=l-1){
			cout<<s<<endl;
		}
		else{
			string q = s.substr(k,l-2*k);
			vector<int>res=manacher(q);
			int le = q.length();
			int ans1 = 0,ans2=0; 
			for(int i=0;i<2*le-1;i++){
				if(i%2==1&&res[i]==(i+1)/2)ans1=max(ans1,res[i]*2);
				if(i%2==0&&res[i]==i/2)ans1=max(ans1,2*res[i]+1);
			}
			reverse(q.begin(), q.end());
			res=manacher(q); 
			for(int i=0;i<2*le-1;i++){
				if(i%2==1&&res[i]==(i+1)/2)ans2=max(ans2,res[i]*2);
				if(i%2==0&&res[i]==i/2)ans2=max(ans2,2*res[i]+1);
			}
			
			
			if(ans1>ans2){
				 t1 = s.substr(0,k) +s.substr(k,ans1)+ s.substr(l-k,k);
				cout<<t1<<endl; 
				
			}
			else{
				 t1 = s.substr(0,k) +s.substr(l-k-ans2,ans2)+ s.substr(l-k,k);
				cout<<t1<<endl;
			} 
		}
		
	}

	return 0;
}
