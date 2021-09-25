#include<bits/stdc++.h>
using namespace std;
#define int long long
#define fi first
#define se second
#define inf INT_MAX
#define mp make_pair
#define pb push_back
const int mod = 998244353;
int qp(int a,int b){int ans=1;while(b){if(b&1)ans*=a,ans%=mod;a*=a,a%=mod;b>>=1;}return ans;};

int A[500005];
int B[500005];

struct node{
	int x,y;
}e[500005];
struct node1{
	double x1;int y1;
}f[500005];
bool cmp(node a,node b){
	if(a.x==b.x){
		return a.y>b.y;
	}else 
	return a.x<b.x;
}

signed main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>e[i].x>>e[i].y;
		}
		
		sort(e+1,e+n+1,cmp);
		
		vector<pair<int,int> >Q;
		//int cnt = 0;
		Q.pb(make_pair(e[1].x,e[1].y )); 
		for(int i=2;i<=n;i++){
			pair<int,int>p = Q.back(); 
			if(e[i].x==p.first){
				continue;
			}
			if(e[i].y>p.second)Q.pb(mp(e[i].x,e[i].y));
		}
		
		int l = Q.size();
//		cout<<"Q.size()="<<Q.size()<<endl;
//		for(int i=0;i<l;i++){
//			cout<<Q[i].fi<<" "<<Q[i].se<<endl;
//		} 
		f[0].x1=0.0,f[0].y1=0;
		//stack<int>P;P.push(0);
		double u;
		int cnt = 0;
		for(int i=1;i<l;i++){
			int cn = f[cnt].y1;
			u  = (double)(-Q[i].first+Q[cn].first)/(double)(-Q[i].second+Q[cn].second);
			//cout<<"u="<<u<<endl;
			
			if(u>f[cnt].x1){
				//cout<<"u---"<<endl;
				cnt++;
				f[cnt].x1 = (-Q[i].first+Q[cn].first)/(Q[i].second-Q[cn].second);
				f[cnt].y1 = i;
			
			}
			else{
				while((double)(-Q[i].first+Q[cn].first)/(double)(-Q[i].second+Q[cn].second)<f[cnt].x1){
					cnt--;
				}				
				f[cnt].x1 =(double) (-Q[i].first+Q[cn].first)/(double)(Q[i].second-Q[cn].second);
				f[cnt].y1 = i;
			}
			//cout<<i<<" "<<cnt<<endl;
		}
		cout<<cnt+1<<endl;
	}
	return 0;
}


