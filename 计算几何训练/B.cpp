#include<iostream>
#include<cstdio>
#include<set>
#include<algorithm>
using namespace std;
class Point{
public:
	double x,y;
	Point(double x=0,double y=0):x(x),y(y){}
	Point operator -(const Point& p)const {
		return Point(x - p.x,y - p.y); 
	}
	bool operator == (const Point& p)const{
		return x==p.x&&y==p.y;
	}
	double cross(const Point &p)const{
		return x * p.y - y*p.x;
	}
};
Point e[3000];
class Line{
public:
	Line() {}
	Point a,b;
	Line(Point a,Point b):a(a),b(b){}
	int toLeftTest(Point p) {
        if((b - a).cross(p - a) > 0) return 1;
        else if((b - a).cross(p - a) < 0) return -1;
        return 0;
    }
};
Line L[1000];
signed main(){
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		for(int i=1;i<=n;i++){
			scanf("%lf%lf%lf%lf",&L[i].a.x,&L[i].a.y,&L[i].b.x,&L[i].b.y);
			e[2*i-1] = L[i].a;e[2*i] = L[i].b; 
		}
		random_shuffle(e+1,e+2*n+1);
		if(n<=2){
			cout <<"Yes!"<<endl;continue;
		}
		bool flag = 0;
		for(int i=1;i<=2*n;i++){
			for(int j=i+1;j<=2*n;j++){
				if(e[i]==e[j])continue;
				Line l(e[i],e[j]);
				bool flag1 = 1;
				for(int k=1;k<=n;k++){
					if((e[j]-e[i]).cross(L[k].a-e[i])*(e[j]-e[i]).cross(L[k].b-e[i])>0){flag1 = false;break;}
				}
				flag = (flag||flag1);
			}
			if(flag){
				puts("Yes!");
				break;
			}
		}
		if(!flag){puts("No!");}
	}
}



