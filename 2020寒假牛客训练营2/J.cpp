#include<bits/stdc++.h>
using namespace std;
#define MAXN 3
#define mod 1000000007
struct Matrix {
    long long int mat[MAXN][MAXN];
    Matrix() {}
    Matrix operator*(Matrix const &b)const {
        Matrix res;
        memset(res.mat, 0, sizeof(res.mat));
        for (int i = 0 ; i < MAXN; i++)
            for (int j = 0; j < MAXN; j++)
                for (int k = 0; k < MAXN; k++)
                    res.mat[i][j] = (res.mat[i][j]+this->mat[i][k] * b.mat[k][j]%(mod-1))%(mod-1);
        return res;
    }
};
Matrix pow_mod(Matrix base, long long int n) {
    Matrix res;
    memset(res.mat, 0, sizeof(res.mat));
    for (int i = 0; i < MAXN; i++)
        res.mat[i][i] = 1;
    while (n > 0) {
        if (n & 1)
            res = res*base;
        base = base*base;
        n >>= 1;
    }
    return res;
}
long long qpow(long long a, long long b)
{
	long long sum = 1;
	a = a % mod;
	while (b > 0) {
		if (b % 2 == 1)	
			sum = (sum * a) % mod;
		b /= 2;
		a = (a * a) % mod;
	}
	return sum;
}
int main() {
    Matrix B;
    long long int n,x,y,a,b;
    cin>>n>>x>>y>>a>>b;
    x %= mod;
    y%=mod;
    if(n==1){
    	cout<<(int)x%mod<<endl;
    	return 0;
	}
	if(n==2){
    	cout<<(int)y%mod<<endl;
    	return 0;
	}
    memset(B.mat,0,sizeof(B.mat));
    B.mat[0][0]=1;B.mat[0][1]=1;B.mat[0][2]=1;B.mat[1][0]=1;B.mat[2][2]=1;
	Matrix C=pow_mod(B,n-2);
    cout<<((qpow(y,C.mat[0][0])*(qpow(x,C.mat[0][1]))%mod*(qpow(qpow(a,b),C.mat[0][2])))%mod)<<endl;

}
