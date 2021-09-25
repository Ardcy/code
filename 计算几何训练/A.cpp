#include<iostream>
#include<set>
#include<algorithm>
using namespace std;

struct node{
	double x,y;
	node(double x=0,double y=0):x(x),y(y){}
	node operator -(const node& p)const {
		return node(x - p.x,y - p.y); 
	}
}b[2000];
struct line{
	node a,b;
	bool operator < (const line &Y)const{
		return a.x < Y.a.x;
	}
}L[2000];
int p[2000];


int check(node a,node b,node c){
	node a1 = c - a;
	node a2 = b - a;
	if((a1.x * a2.y - a1.y * a2.x) > 0)return 1 ;else return -1; 
}
signed main(){
	int n;
	while(cin >> n){
		for(int i=0;i<=n;i++)p[i] = 0;
		if(n==0)break;
		int m;
		double x1,y1,x2,y2;
		cin >> m >> x1 >> y1 >> x2 >> y2;
		for(int i=1;i<=n;i++){
			double u,v;
			cin >> u >> v;
			L[i].a = {u,y1};L[i].b = {v,y2};
		}
		L[0].a = {x1,y1};
		L[0].b = {x1,y2};
		L[n+1].a = {x2,y1};L[n+1].b = {x2,y2};
		sort(L+1,L+n+1);
		for(int i=1;i<=m;i++){
			cin >> b[i].x >> b[i].y;
		}
		double ans = 0;
		cout << "Box"<< endl;
		for(int i=1;i<=m;i++){
			for(int j=0;j<=n;j++){

				if(check(L[j].a,L[j].b,b[i])*check(L[j+1].a,L[j+1].b,b[i])==-1){
					p[j]++;
				}
			}
		}
		multiset<int>P;set<int>Y;
		for(int i=0;i<=n;i++){
			P.insert(p[i]);Y.insert(p[i]);
		}
		for(set<int>::iterator u=Y.begin();u!=Y.end();u++){
			
			if(*u)
			cout << (*u) << ": " << P.count(*u) << endl;
		}

	}

}