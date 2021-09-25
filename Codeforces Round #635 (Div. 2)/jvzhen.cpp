#pragma comment(linker, "/STACK:102400000000,102400000000")
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
int mod=3;
struct mat {
	int r,c;
	int m[1600][1600];
	mat() {}
	mat(int r,int c):r(r),c(c) {}
	void clear() {
		memset(m,0,sizeof(m));
	}

	mat operator+(mat a)const {
		mat ans(r,c);
		for(int i=1; i<=r; i++) {
			for(int j=1; j<=c; j++) {
				ans.m[i][j]=(m[i][j]+a.m[i][j])%mod;
			}
		}
		return ans;
	}

	mat operator*(mat a)const {
		mat tmp(r,a.c);
		int i,j,k;
		for(i=1; i<=tmp.r; i++) {
			for(j=1; j<=tmp.c; j++) {
				tmp.m[i][j]=0;
				for(k=1; k<=c; k++) {
					tmp.m[i][j]=(tmp.m[i][j]+(m[i][k]*a.m[k][j])%mod)%mod;
				}
			}
		}
		return tmp;
	}

	mat operator^(int n)const {
		mat ans(r,r),tmp(r,r);
		memcpy(tmp.m,m,sizeof(tmp.m));
		ans.clear();
		for(int i=1; i<=ans.r; i++) {
			ans.m[i][i]=1;
		}
		while(n) {
			if(n&1)ans=ans*tmp;
			n>>=1;
			tmp=tmp*tmp;
		}
		return ans;
	}

	void print()const {
		for(int i=1; i<=r; i++) {
			for(int j=1; j<=c; j++) {
				printf("%d",m[i][j]);
				if(j==c)printf("\n");
				else printf(" ");
			}
		}
	}

};
mat a,b,c;
int main() {
	int n;
	cout<<"haha"<<endl;
	while(~scanf("%d",&n)) {
		a.r=a.c=b.r=b.c=n;
		for(int i=1; i<=n; i++)
			for(int j=1; j<=n; j++)
				scanf("%d",&a.m[i][j]);
		for(int i=1; i<=n; i++)
			for(int j=1; j<=n; j++)
				scanf("%d",&b.m[i][j]);
		
		c=a*b;
		c.print();

	}
}

