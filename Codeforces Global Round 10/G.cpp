#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
using namespace std;
#define pb push_back
const int mod = 998244353;
const int N = 200500;
int qp(int a,int b) {
	int ans=1;
	while(b) {
		if(b&1)ans*=a,ans%=mod;
		a*=a,a%=mod;
		b>>=1;
	}
	return ans;
};
int a[1000],end1;
set<int> F;
vector<int>P;

int f = 10;
int cnt = 1;
int l1  = 0;

int c[1000];
void Combination(int m, int n) {
	for (int i = m; i >= n; i--) {
		a[n] = c[i];
		if (n > 1) {
			Combination(i - 1, n - 1);
		} else {
			P.clear();
			for (int j = 1; j <= end1; j++) {
				P.pb(a[j]);
			}
			F.clear();
			for(int j=1; j<(1<<l1); j++) {
				int sum  = 0;
				for(int p=0; p<l1; p++) {
					if((1<<p)&j)sum+=P[p];
				}
				F.insert(sum);
			}
			int l = F.size();
			int l2 = qp(2,l1)-1;
			if(F.size()==l2) {
//				cout<<"子集和分别为：";
//				for(int  p:F)cout<<p<<" ";
//				cout<<endl;
//				cout<<"case "<<cnt<<":";
//				for (int j = 1; j <= end1; j++) cout<<P[j-1]<<" ";
				//cout<<endl;
				if(cnt)cout<<cnt<<endl;
				cnt++;
			}
		}
	}
}

int b[100];
void isright() {

	F.clear();
	for(int j=1; j<(1<<l1); j++) {
		int sum  = 0;
		for(int p=0; p<l1; p++) {
			if((1<<p)&j)sum+=b[p];
		}
		F.insert(sum);
	}
	int l = F.size();
	int l2 = qp(2,l1)-1;
	cout<<l<<endl;
	if(F.size()==l2) {
		cout<<"子集和分别为：";
		for(int  p:F)cout<<p<<" ";
		cout<<endl;
		cout<<"case "<<cnt<<":";
		for (int j = 1; j <= end1; j++) cout<<P[j-1]<<" ";
		cout<<endl;
		cnt++;
	}
}

signed main() {






//	while(1) {
//		int m, n;
//		int i;
//		cin>>m>>n;
//		vector<int>v;
//		for(int i=1; i<=m; i++)v.pb(i);
//		random_shuffle(v.begin(),v.end());
//		for(int i=1; i<=m; i++)c[i]=v[i-1];
//		l1 = n;
//		end1 = n;
//		Combination(m, n);
//		cout<<"ove"<<endl;
//		cout<<cnt<<endl;
//	}
l1 =7;
for(int i=0;i<l1;i++)cin>>b[i];
/*500 499 498 496 493 487 467 439 323
500 499 497 494 26 38 65  51 490  
*/
isright();
//for(int i=1;i<500;i++){
//	b[9]=i;isright();
//}
//	while(1) {
//		cin>>l1;
//
//		for(int i=0; i<l1; i++)cin>>b[i];
//		isright();
//
//		cout<<"over"<<endl;
//	}
	return 0;
}

