#include<bits/stdc++.h>
using namespace std;
#define int long long
const double  Pi = acos(-1.0);
signed main() {
	int n,r;
	cin>>n>>r;
	int i,j;
	cin>>i>>j;
	int mini = min(abs(i-j),n-abs(i-j)); 
	double l =  2*r * (double)sin(Pi*1.0/n) *mini;
	printf("%.10f",l);
}
