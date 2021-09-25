#include<bits/stdc++.h>
using namespace std;
const int p = 1e5+5;
const int N = 3;
struct Mat {
	double mat[N][N];
} M[p];
Mat matrixmult(Mat a,Mat b) {
	int i,j,k;
	Mat c;
	for(i=0; i<N; i++) {
		for(j=0; j<N; j++) {
			c.mat[i][j]=0;
			for(k=0; k<N; k++)
				c.mat[i][j]+=(a.mat[i][k]*b.mat[k][j]);
		}
	}
	return c;
}
double getA(double arcs[N][N],int n) {
	if(n==1)return arcs[0][0];
	double ans = 0;
	double temp[N][N]= {0.0};
	int i,j,k;
	for(i=0; i<n; i++) {
		for(j=0; j<n-1; j++) {
			for(k=0; k<n-1; k++) {
				temp[j][k] = arcs[j+1][(k>=i)?k+1:k];
			}
		}
		double t = getA(temp,n-1);
		if(i%2==0) {
			ans += arcs[0][i]*t;
		} else {
			ans -=  arcs[0][i]*t;
		}
	}
	return ans;
}
Mat  getAStart(double arcs[N][N],int n) {
	double ans[N][N];
	int i,j,k,t;
	double temp[N][N];
	for(i=0; i<n; i++) {
		for(j=0; j<n; j++) {
			for(k=0; k<n-1; k++) {
				for(t=0; t<n-1; t++) {
					temp[k][t] = arcs[k>=i?k+1:k][t>=j?t+1:t];
				}
			}
			ans[j][i]  =  getA(temp,n-1);
			if((i+j)%2 == 1) {
				ans[j][i] = - ans[j][i];
			}
		}
	}
	Mat G;
	for(i=0; i<N; i++)for(j=0; j<N; j++)G.mat[i][j]=ans[i][j];
	double  f1 = getA(G.mat,3);
	for(i=0; i<N; i++)for(j=0; j<N; j++)G.mat[i][j]/=f1;
	return G;
}
Mat getinv(Mat Mf) {
	Mat MF;
	int n=3;
	MF = getAStart(Mf.mat,n);
	return MF;
}

signed main() {
	M[0].mat[0][0]=M[0].mat[1][1]=M[0].mat[2][2]=1.0;
	int n,t;
	scanf("%d%d",&n,&t);
	for(int i=1,f; i<=n; i++) {
		scanf("%d",&f);
		Mat r;
		//for(int i1=0;i1<3;i1++)for(int j=0;j<3;j++)r.mat[i1][j]=0.0;
		if(f==1) {
			double u,v;
			scanf("%lf%lf",&u,&v);
			r.mat[0][0]=r.mat[1][1]=r.mat[2][2]=1.0;
			r.mat[0][2]=u;
			r.mat[1][2]=v;
		} else {
			double u;
			scanf("%lf",&u);
			r.mat[2][2]=1;
			r.mat[0][0]=cos(u);
			r.mat[0][1]=-sin(u);
			r.mat[1][0]=sin(u);
			r.mat[1][1]=cos(u);
		}
		M[i]=matrixmult(r,M[i-1]);
	}
	while(t--) {
		int a,b;
		scanf("%d%d",&a,&b);
		Mat U;
		U=matrixmult(M[b],getinv(M[a-1]));
		printf("%.3f %.3f\n",U.mat[0][2],U.mat[1][2]);
	}
	return 0;
}

