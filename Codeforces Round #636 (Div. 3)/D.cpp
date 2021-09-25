#include<bits/stdc++.h>
using namespace std;
#define int long long
#define fi first
#define se second
#define inf INT_MAX
#define mp make_pair
int n;
int a[400005] = {0};
int sum1[450005];    
int sum2[450005];   

int lowbit(int x) {
	return x&(-x);
}

void updata(int i,int k) {
	int x = i;    
	while(i <= n) {
		sum1[i] += k;
		sum2[i] += k * (x-1);
		i += lowbit(i);
	}
}

int getsume(int i) {      
	int res = 0, x = i;
	while(i > 0) {
		res += x * sum1[i] - sum2[i];
		i -= lowbit(i);
	}
	return res;
}



signed main() {
	int t;
	cin>>t;
	while(t--) {
		int k,n1;
		cin>>n1>>k;
		n=max(n1,2*k);
		for(int i=1; i<=max(n1,2*k); i++) {
			a[i]=0;
			sum1[i]=0;
			sum2[i]=0;
		}
		for(int i = 1; i <= n1; i++) {
			cin>>a[i];
			//updata(i,a[i] - a[i-1]);   //输入初值的时候，也相当于更新了值
		}

		for(int i=1; i<=n1/2; i++) {
			int a1,a2,a3,a4;
			a1=max((int)2,min(a[i],a[n1-i+1])+1);
			a2 = a[i]+a[n1-i+1]-1;
			a3 = a[i]+a[n1-i+1]+1;
			a4 = min(max(a[i],a[n1-i+1])+k,(int)2*k);
//			cout<<a1<<" "<<a2<<" "<<a3<<" "<<a4<<endl;


			if(2<a1) {
				updata(2,2);   
				updata(a1,-2);       
//				cout<<"1:           "<<2<<" "<<(a1-1)<<endl;
			}
			if(a1<=a2) {
				updata(a1,1);   
				updata(a2+1,-1);     
//				cout<<"2:           "<<a1<<" "<<(a2)<<endl;
			}
			if(a3<=a4) {
				updata(a3,1);    
				updata(a4+1,-1);       
//				cout<<"3:           "<<a3<<" "<<(a4)<<endl;
			}
			if(a4+1<=2*k) {
				updata(a4+1,2);   
				updata(2*k+1,-2);        
//				cout<<"4:           "<<(a4+1)<<" "<<(2*k)<<endl;
			}

		}
		int ans = 1e14;
		for(int i=2; i<=2*k; i++) {

			ans = min(ans,getsume(i)-getsume(i-1));
		}
//		for(int i=1; i<=2*k; i++) {
//			cout<<"sum="<<i<<" "<<(getsume(i)-getsume(i-1))<<endl;
//		}
		cout<<ans<<endl;
	}
	return 0;
}


