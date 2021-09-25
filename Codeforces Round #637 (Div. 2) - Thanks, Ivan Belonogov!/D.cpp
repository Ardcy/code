#include<bits/stdc++.h>
using namespace std;
#define int long long
#define fi first
#define se second
#define inf INT_MAX
#define mp make_pair
int b[]= {119,18,93,91,58,107,111,82,127,123};
int d[3000];
struct no {
	int x,y;
};
struct node {
	no a[10];
	int cnt = 0;
} e[128];
bool cmp(no a,no b) {
	if(a.y==b.y)return a.x<b.x; 
	else return a.y<b.y;
}
int f1[105000];
int f2[105000];
int f3[105000];
int ans[10500];
signed main() {
	cout<<bitset<7>(127);
	int y=0;
	for(int j=0; j<128; j++) {
		for(int i=0; i<10; i++) {
			if((j|b[i])<=b[i]) {
				//	cout<<j<<" "<<i<<" "<<bitset<sizeof(127)*8>((j^b[i])).count()<<endl;
				int cnt = e[j].cnt;
				e[j].a[cnt].x=i;
				e[j].a[cnt].y=bitset<sizeof(127)*8>((j^b[i])).count();
				e[j].cnt++;
				y++;
			}
		}
	}
	for(int i=0; i<128; i++) {
	//	cout<<"i="<<i<<endl;
		sort(e[i].a+0,e[i].a+e[i].cnt,cmp);
		for(int j=0; j<e[i].cnt; j++) {
	//		cout<<e[i].a[j].x<<" "<<e[i].a[j].y<<" ";
		}
		//cout<<endl;
	}
//	cout<<y<<endl;
	int n,k;
	cin>>n>>k;
	bitset<7>bin;
	int g = 0;
	for(int i=1; i<=n; i++) {
		cin>>bin;
		d[i]=bin.to_ulong();
		f1[i]=e[d[i]].a[0].y;
		//cout<<f1[i]<<endl;
	}
	for(int i=n; i>=1; i--) {
		f2[i] = f2[i+1] + f1[i];
	}
	if(f2[1]>k) {
		cout<<-1<<endl;
		return 0;
	} else {
		for(int k1=1; k1<=n; k1++) {
			int i=d[k1];
			cout<<"i="<<i<<" "<<k<<endl;
			int u = 0;		
			int num = k-f2[k1+1];
			cout<<num<<endl;
			for(int j=0; j<e[i].cnt; j++) {
				if(e[i].a[j].y<=num&&ans[k1]<e[i].a[j].x) {
					ans[k1]=e[i].a[j].x;
					u=e[i].a[j].y;
//					cout<<"---- ";
//					cout<<ans[k1]<<" ";
//					cout<<u<<endl;
				}	
			}
			k-=u;
			//cout<<"k="<<k<<endl;
			//cout<<ans[k1]<<" ";
		}
		cout<<endl;
		if(k>0) {
			for(int k1=n; k1>=1; k1--) {
				int i=ans[k1];
				for(int j=0; j<e[i].cnt; j++) {
					int num=k1;
					int u = bitset<sizeof(127)*8>(ans[i]).count();
					int h = 0;int ff1=0;
					if(e[i].a[j].y<=num-u) {
						h=j;
						ff1=1;
//						ans[i]=e[i].a[j].x;
//						u=e[i].a[j].y;
//						k-= e[i]. bitset<sizeof(127)*8>(ans[i]).count();
					}
					if(ff1==1){
						ans[k1]=e[i].a[h].x;
						k-=e[i].a[h].y;
					}
					k-=u;
				}
				if(k == 0) break;
			}
		}
		if(k>0) cout<<-1<<endl;
		else {
			for(int i=1;i<=n;i++)cout<<ans[i];cout<<endl;
		}

	}
	return 0;
}


