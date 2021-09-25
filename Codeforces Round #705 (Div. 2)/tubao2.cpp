#include<bits/stdc++.h>
using namespace std;
struct node{
	double x,y,p;
	node(double x=0,double y=0):x(x),y(y){}
	friend node operator-(const node&a,const node&b){return node(a.x-b.x,a.y-b.y);}
	friend double operator^(const node a,node b){
		return a.x * b.y - a.y * b.x;
	}
}a[50005];
node ini;
double eps = 1e-8;
int n,top;
double ans;
int s[50005];
double f(node a,node b){
	return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}
bool cmp(node a,node b){
	if(fabs(a.p - b.p) < eps){
		node e(0,0);
		return f(e,a) < f(e,b);
	}
	return a.p < b.p;
}

signed main(){
	cin >> n;
	int zz = 1;
	for(int i=1;i<=n;i++){
		cin >> a[i].x >> a[i].y;
		if(a[i].y<a[zz].y||(a[i].y==a[zz].y&&a[i].x<a[zz].x)){
			zz = i;
		}
	}
	swap(a[1],a[zz]);
	ini = a[1];
	for(int i=2;i<=n;i++){
		a[i].x -= a[1].x;a[i].y -= a[1].y;
		a[i].p = atan2(a[i].y,a[i].x);
	}
	sort(a+2,a+1+n,cmp);
	a[1].x = 0;a[1].y = 0;
	s[1] = 1;
	s[2] = 2;
	s[3] = 3;
	top = 3;
	for(int i=4;i<=n;i++){
		while(top >= 3&& ((a[s[top]] - a[s[top-1]])^(a[i]-a[s[top]]))<=0){
			top--;
		}
		s[++top] = i;
	}
	for(int i=1;i<=top-1;i++){
		ans += f(a[s[i]],a[s[i+1]]);
	}
	ans += f(a[n],a[1]);
	printf("%.2lf\n",ans);
}