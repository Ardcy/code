#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 205;
const double PI = acos(-1);
const double base = 2*PI/3;

double L,x,y,vx,vy,h;
int k;

struct Point{
	double x,y;
	Point(){}
	Point(double x,double y){
		this->x = x;
		this->y = y;
	}
};
Point Rotate(Point a,double rad){
	return Point(a.x * cos(rad) - (a.y)*sin(rad),a.x*sin(rad)+(a.y)*cos(rad));
}
bool check(double t){
	ll num = 0;
	Point now = Point(x+t*vx,y + t*vy);
	Point p1 = Rotate(now,base*0);
	num += abs(floor(p1.y/h));
	Point p2 = Rotate(now,base*1);
	p2.y += h/2;
	num += abs(floor(p2.y/h));
	Point p3 = Rotate(now,base*2);
	p3.y += h/2;
	num += abs(floor(p3.y/h));
	return num >= k;
}

signed main(){
	int t;
	scanf("%d",&t);
	while(t--){
		scanf("%lf%lf%lf%lf%lf%d",&L,&x,&y,&vx,&vy,&k);
		h = sqrt(3)/2*L;
		double l = 0,r = 1e11;
		while(r - l > 1e-6){
			double mid = (l+r)/2;
			if(check(mid)){
				r = mid;
			}else{
				l = mid;
			}
		}
		printf("%.10f\n",(l+r)/2);
	}
}