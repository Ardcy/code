#include <bits/stdc++.h>
#define int long long
#define double long double
#define ull unsigned long long
#define pb push_back
#define sf(n)       scanf("%lld", &n)
#define sff(a,b)    scanf("%lld%lld", &a, &b)
#define sfff(a,b,c) scanf("%lld%lld%lld", &a, &b, &c)
#define debug printf("Here\n")
#define out(x) cout << x << endl
#define out2(x, y) cout << x << " " << y << endl
#define out3(x, y, z) cout << x << " " << y << " " << z << endl
#define out4(a, b, c, d) cout << a << " " << b << " " << c << " " << d << endl
using namespace std;
 
inline int read()
{
    int p;
    cin >> p;
    return p;
}
 
const int MAXN = 10 + 10;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;
const double eps = 1e-9;
const double PI = acos(-1.0);
 
struct Point
{
	double x, y;
} points[MAXN], o, s, t;
 
int n;

double distance(Point a, Point b)
{
	double x1 = a.x, y1 = a.y, x2 = b.x, y2 = b.y;
	return sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
}

double check()
{
	 double x1 = s.x, y1 = s.y, x2 = t.x, y2 = t.y, x0 = o.x, y0 = o.y;
	// return ((x1 - x0) * (y2 - y0) - (y1 - y0) * (x2 - x0)) > 0;

	double theta1 = atan2(y2-y0,x2-x0),theta2 = atan2(y1-y0,x1-x0);
	theta1 = fabs(theta1 - theta2);
	while(theta1  > 2*PI){
		theta1 -= 2*PI;
	}
	while(theta1  < 0){
		theta1 += 2*PI;
	}
	return theta1;
}

signed main()
{
	int kase = 1;
    while (cin >> o.x >> o.y >> s.x >> s.y >> t.x >> t.y)
    {
    	if (fabs(o.x) < eps && fabs(o.y) < eps && fabs(s.x) < eps && fabs(s.y) < eps && fabs(t.x) < eps && fabs(t.y) < eps) break;
    	cin >> n;
    	// cout<<"--------"<<endl;
    	// out(n);
    	// cout << "---------" << endl;
    	for (int i = 0; i < n; i++)
    	{
    		cin >> points[i].x >> points[i].y;
    	}
    	double inner_ans = distance(points[0], s) + distance(points[n - 1], t);
    	for (int i = 1; i < n; i++)
    	{
    		inner_ans += distance(points[i], points[i - 1]);
    	}
    	double d = distance(s, t), r = distance(o, s);
    	
        //double outer_ans = min(check(),2*PI - check()) * r;
    	
         double outer_ans =  2*(asin(d / (r * 2))) * r;
     
        outer_ans =min(2.0 * PI * r - outer_ans,outer_ans) ;

        cout << "Case #" << kase++ << ": ";
    	if (inner_ans < outer_ans) cout << "Watch out for squirrels!" << endl;
    	else cout << "Stick to the Circle." << endl;
    	cout << endl;
    	//cout << n << endl;
    }
    return 0;
}