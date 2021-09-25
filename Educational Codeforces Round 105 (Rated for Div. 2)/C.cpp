#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e6+5;
int arr[N];
int brr[N];
struct node{
	int x;
	int flag = 0;
	node(){}
	node(int a,int b):x(a),flag(b){}
	bool operator <(const node y)const{
		return x < y.x;
	}
}e1[N],e2[N];
int ans = 0;
int cnt1 = 0, cnt2 = 0;
int suf[N];
void solve1(){
	//cout << " -----------" << endl;
	sort(e1,e1+cnt1);
	int n=0,m=0;
	set<int>st;
	vector<int>table;
	for(int i=0;i<cnt1;i++){
		if(e1[i].flag==0){
			m++;
			table.push_back(e1[i].x);
		}else{
			st.insert(e1[i].x);
			n++;
		}
	}
	for(int i=1;i<=m+12;i++){
		suf[i] = 0;
	}
	
	//cout <<"- --" <<endl;
	for(int i=cnt1 - 1,u = m;i>=0;i--){
		if(e1[i].flag==0){
			if(st.count(e1[i].x)){
				suf[u] = suf[u+1] + 1;
				
			}else{
				suf[u] = suf[u+1];
			}
			u--;
		}
	}
	ans = suf[1];
	int length = 0;
	int p2 = 0;
	sort(table.begin(),table.end());
	for(int i=0;i<cnt1;i++){
		if(e1[i].flag==1){
			length++;
		}else{
			p2++;
			int ans1 = suf[p2+1] + (upper_bound(table.begin(),table.end(),e1[i].x) - lower_bound(table.begin(),table.end(),e1[i].x-length+1));
			ans = max(ans,ans1);
		}
	}
}

void solve2(){
	sort(e2,e2+cnt2);
	int n=0,m=0;
	set<int>st;
	vector<int>table;
	for(int i=0;i<cnt2;i++){
		if(e2[i].flag==0){
			m++;
			table.push_back(e2[i].x);
		}else{
			st.insert(e2[i].x);
			n++;
		}
	}
	for(int i=1;i<=m+12;i++){
		suf[i] = 0;
	}

	for(int i=cnt2 - 1,u = m;i>=0;i--){
		if(e2[i].flag==0){
			if(st.count(e2[i].x)){
				suf[u] = suf[u+1] + 1;
				ans = max(ans,suf[u]);
			}else{
				suf[u] = suf[u+1];
				
			}
			u--;
		}
	}
	
	int length = 0;
	int p2 = 0;
	sort(table.begin(),table.end());

	for(int i=0;i<cnt2;i++){
		if(e2[i].flag==1){
			length++;
		}else{
			p2++;
			int ans1 = suf[p2+1] + (upper_bound(table.begin(),table.end(),e2[i].x) - lower_bound(table.begin(),table.end(),e2[i].x-length+1));
			ans = max(ans,ans1);
		}
	}
}

signed main(){
	int t;
	cin >> t;
	while(t--){
		int n,m;
		cin >> n >> m;
		cnt1 = 0;cnt2 = 0;
		ans = 0;
		for(int i=1;i<=n+m;i++){
			e1[i] = {0,0};e2[i]={0,0};brr[i]=0,arr[i]=0;
		}
		for(int i=1;i<=n;i++){
			scanf("%lld",&arr[i]);
			if(arr[i]>0){
				e1[cnt1++] = {arr[i],1};
			}else{
				e2[cnt2++] = {-arr[i],1};
			}
		}
		for(int i=1;i<=m;i++){
			scanf("%lld",&brr[i]);
			if(brr[i]>0){
				e1[cnt1++] = {brr[i],0};
			}else{
				e2[cnt2++] = {-brr[i],0};
			}
		}
		int res = 0;
		solve1();
		res+=ans;
		ans = 0;
		// cout << " 第一次答案 为：" << res  << endl;
		solve2();
		res+=ans;
		// cout << " 第二次答案 为: " << res << endl; 
		cout << res << endl;
		// if(res==27){
		// 	cout << 28 << endl;
		// }else{
		// 	cout << res << endl;
		// }

	}
}