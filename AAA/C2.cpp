#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
#include<cmath>
#define INF 0x3f3f3f3f
#define PI acos(-1.0)
#define pi acos(-1.0)
using namespace std;
const double eps =1e-12;
const int maxn = 520;
struct Node{
	double x;
	double y;
}a[maxn];
int n;
double C(double degree){
	double x,y,maxx,maxy,minx,miny;
	maxx = maxy = -INF;
	minx = miny = INF;
	for(int i=0;i<n;i++){
		x=a[i].x*cos(degree)-a[i].y*sin(degree);
		y=a[i].x*sin(degree)+a[i].y*cos(degree);
		maxx=max(maxx,x);
		maxy=max(maxy,y);
		minx=min(minx,x);
		miny=min(miny,y);
	}
	return max(maxx-minx,maxy-miny);
}
double bsearch(){
	double left=0,right=PI/2.0;
	double midl,midr;
	while(right-left>eps){
		midl=(left+right)/2;
		midr=(midl+right)/2;
		if(C(midl)<C(midr)){
			right=midr;
		}
		else{
			left=midl;
		}
	}
	return C(left);
}
int main()
{
	int T;
	cin>>T;
	while(T--){
		cin>>n;
		
		a[0].x=0.0;a[0].y=0.0;
		int cnt = 1;
		double inner = 180.0 - 360.0/(2*n);
		double outer = 180.0 - inner;
		double pre =  inner/2;
		double now = pre;
	//	cout<<pre<<endl;
		double prex = 0, prey = 0;
		for(int i=1;i<n;i++){
			
			prex = prex + cos(now/180*pi);
			prey = prey + sin(now/180*pi);
	//		cout<<"now="<<now<<endl;
			a[cnt].x=prex;a[cnt].y=prey;
			cnt++;
			
			a[cnt].x=prex;a[cnt].y=-prey;
			cnt++;
			now -= outer;
			
			
		}
//		cout<<"now="<<now<<endl;

		prex = prex + cos(now/180*pi);
			prey = prey + sin(now/180*pi);
			
			a[cnt].x=prex;a[cnt].y=prey;
		n*=2;
//		cout<<"cnt="<<cnt<<endl;
//				for(int i=0;i<=cnt;i++){
//			cout<<a[i].x<<" "<<a[i].y<<endl;
//		}
		double low = bsearch();
		printf("%.12lf\n",low);
	}
	return 0;
}
