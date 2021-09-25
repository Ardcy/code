#include<algorithm>
#include<cstdio>
#include<iostream>
#include<cmath>
#include <iomanip>
using namespace std;

struct Point{
	double x,y;
	Point(double x=0,double y=0):x(x),y(y){}
	bool operator == (const Point &p)const{
		return x == p.x && y==p.y;
	}
	double cross(const Point &p)const{
		return x * p.y - y*p.x;
	}
	Point operator- (const Point &p){
		return Point(x-p.x,y-p.y);
	}
};
struct line{
	Point a,b;
	line(){}
	line(Point a,Point b):a(a),b(b){}
};
const double eps = 1e-8;
signed main(){
	int t;
	
	cout <<fixed<< setprecision(2);
	cin >> t;
	cout << "INTERSECTING LINES OUTPUT" << endl;
	while(t--){
		line A,B;
		cin >> A.a.x >> A.a.y;
		cin >> A.b.x >> A.b.y;
		cin >> B.a.x >> B.a.y;
		cin >> B.b.x >> B.b.y;
		if(fabs((A.b.y - A.a.y)*(B.b.x - B.a.x)-(A.b.x - A.a.x) * (B.b.y - B.a.y)) < eps){
			if(fabs((B.a - A.a).cross(B.b-A.a))<eps){
				cout << "LINE" << endl;
			}else{
				cout << "NONE" << endl;
			}
		}else{
			Point u = A.a - B.a;
			Point v = A.b - A.a;
			Point w = B.b - B.a;
			double t = w.cross(u) / v.cross(w);
			double x1,y1;
			x1 = A.a.x + t * v.x;
			y1 = A.a.y + t * v.y;
			cout <<"POINT "<< x1 << " " << y1 << endl;

		}

	}
	cout <<"END OF OUTPUT" << endl;
}