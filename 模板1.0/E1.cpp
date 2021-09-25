#include<bits/stdc++.h>
using namespace std;
namespace IO {
	struct q_instream {
		template < typename classT >
		inline q_instream operator>>(classT &e) const {
			e= 0;
			classT f= 1, c= 0;
			while(c < '0' || c > '9') {
				if(c == '-') f= -1;
				c= getchar();
			}
			while(c >= '0' && c <= '9') e= e * 10 + c - '0', c= getchar();
			return e= e * f, (*this);
		}
	} in;
	//读入优化
	struct q_outstream {
		template < typename classT >
		inline q_outstream operator<<(const classT &e) const {
			if(e < 0) {
				putchar('-');
				(*this) << -e;
			} else {
				if(e > 9) (*this) << (e / 10);
				putchar(e % 10 + '0');
			}
			return (*this);
		}
		inline q_outstream operator<<(const char &c) const {
			return putchar(c), (*this);
		}
	} out;
	//输出优化
}
using namespace IO;
#define int long long
int b[105000];
int n,a,r,m;
//long long get_cost(int rr) {
//	int f1=0,f2=0;
//	for(int i=1; i<=n; i++) {
//		if(b[i]>=rr)f1+=(b[i]-rr);
//		else f2+=(rr-b[i]);
//	}
//	int f3=min(f2,f1);
//	f2-=f3;
//	f1-=f3;
//	return r*f1+a*f2+m*f3;
//}
int sum;
vector<int> h;
vector<long long> cum(n + 1);
int get_cost (long long x) {
	auto res = 0LL;
	if (sum < x * n) {
		res += a * (x * n - sum);
		int j = upper_bound(begin(h), end(h), x) - begin(h);
		res += min(m, a + r) * (cum[j] - (n - j) * x);
	} else {
		res += r * (sum - x * n);
		int j = lower_bound(begin(h), end(h), x) - begin(h);
		res += min(m, a + r) * (j * x - (cum[0] - cum[j]));
	}
	return res;
};
int maxe = 100;
int pos[1000];
int best_ans=0x3f3f3f3f3f3f3f3f;
const double BeginT= 10000, EndT= 1e-22, ChangeT= 0.999;
int  y;
typedef std::subtract_with_carry_engine<std::uint_fast64_t, 48, 5, 12> ranlux48_base;
ranlux48_base rb;
void SA(int times) {
	long long x, pre,tmp_ans;
	while(times--) {
		for(double T= BeginT; T > EndT; T*= ChangeT) {
			pre = x;
			//	x +=  (int)(rb()*ChangeT)%(b[n]+1);
			//	x -=  (int)(rb()*ChangeT)%(b[n]+1);
			//x+=  max(rb()%3,b[1]+(int)((int)(rb())*ChangeT))%(b[n]-b[1])+1);
			x= (b[1]+(int)((int)(rb())*ChangeT))%(b[n]+1-b[1])+1;

			x+=rb()%2;
			x-=rb()%2;

			//if(times==1)cout<<n-times<<" "<<x<<endl;
			tmp_ans= get_cost(x);
			if(tmp_ans <= best_ans) {
				best_ans= tmp_ans;
				y=x;
				//	cout<<x<<endl;
			} else if(exp((best_ans - tmp_ans) / T) > (double)rand() / RAND_MAX) {
				x=pre;
			}
		}
	}
	return;
}

signed main() {
//	int o = rb();
//	cout<<rb.max()<<endl;
//	srand(rand());
//	srand(rand());
	cin>>n>>a>>r>>m;
	int o;
	for(int i=1; i<=n; i++)cin>>b[i],h.push_back(b[i]);
	sort(b+1,b+n+1);

	sort(begin(h), end(h));
	sum = accumulate(begin(h), end(h), 0LL);
	for(int i=0; i<=n; i++)cum.push_back(0);
	for (int i = n; i--; ) {
		cum[i] = h[i] + cum[i + 1];
	}


	SA(25);
	out<<y;
	cout<<endl;
	for(int i=1; i<=n; i++)best_ans=min(best_ans,get_cost(b[i]));
	for(int i=max(y-305000,(int)1); i<=y+305000; i++) {
		best_ans=min(best_ans,get_cost(i));
	}
	cout<<best_ans<<endl;
	//cout<<endl;
	//cout<<y<<endl;
	return 0;
}
