#include<bits/stdc++.h>

using namespace std;

// 以pt1为基准
const double CV_PI = acos(-1.0);
struct Point2f {
	double x,y;
	Point2f(int a,int b) {
		this->x=a,this->y=b;
	}
};
float getAngelOfTwoVector(Point2f &pt1, Point2f &pt2, Point2f &c) {
	float theta = atan2(pt1.x - c.x, pt1.y - c.y) - atan2(pt2.x - c.x, pt2.y - c.y);
	if (theta > 2*CV_PI)
		theta -= 2 * CV_PI;
	if (theta < 0)
		theta += 2 * CV_PI;

	theta = theta * 180.0 / CV_PI;
	return theta;
}

int main() {

	int t,a1,a2,a3,b1,b2,b3;

	cin>>t;
	Point2f c(0, 0);
	while(t--) {

		cin>>a1>>b1>>a2>>b2>>a3>>b3;



		Point2f pt1(a1, b1);
		Point2f pt2(a2, b2);
		Point2f pt3(a3, b3);
		float theta1 = getAngelOfTwoVector(pt1, pt2, c);
		float theta2 = getAngelOfTwoVector(pt1, pt3, c);
		float theta3 = getAngelOfTwoVector(pt2, pt3, c);


		//cout<<theta1<<" "<<theta2<<" "<<theta3<<endl;
		if( (theta2-theta1)>1e-4) {
			cout<<"Counterclockwise"<<endl;
		} else cout<<"Clockwise"<<endl;


	}
}
