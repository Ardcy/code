#include<iostream>
#include<cmath>
#include<algorithm>
#include<cstdio>
#include<map>
using namespace std;
typedef long long LL;
int dir[8][2] = {-1, 1, 0, 1, 1, 1, -1, 0, 1, 0, -1, -1, 0, -1, 1, -1};
int flag, d, u;
//flag为1表示有穷连通，为0表示无穷连通；d为xi求和，u为xk
map<pair<LL, LL>, int> m;//记录点是否good
pair<LL, LL> p;

void dfs(LL x, LL y){
	if(x == y){
		flag = 0;
		return;
	}
	int dd = 1;
	for(int i = 0; i < 8; i++){
			LL xx = x + dir[i][0], yy = y + dir[i][1];
			if(__gcd(xx, yy) > 1) {
				dd++;
				p.first = xx, p.second = yy;
				if(m.count(p)) continue;
				m[p] = 1;
				dfs(xx, yy);
				if(flag == 0) return;
			}
			
		}
	//cout << "x:" << x << "  y:" << y << "   dd:" << dd << endl;
	d += dd;
	
}

int main(){
	int t;
	scanf("%d", &t);
	while(t--){
		LL x, y;
		scanf("%lld%lld", &x, &y);
		if(x == y + 2 || y == x + 2){
			printf("0/1\n");
			continue;
		}
		u = 1;
		d = 1;
		flag = 1;
		m.clear();
		p.first = x, p.second = y;
		m[p] = 1;
		//dfs(x, y);
		for(int i = 0; i < 8; i++){
				LL xx = x + dir[i][0], yy = y + dir[i][1];
				if(__gcd(xx, yy) > 1){
					d++;
					u++;
					p.first = xx, p.second = yy;
					m[p] = 1;
				}
			}

	//cout << "      x:" << x << "  y:" << y << "   d:" << d << endl;
		for(int i = 0; i < 8; i++){
				LL xx = x + dir[i][0], yy = y + dir[i][1];
				if(__gcd(xx, yy) > 1){
					dfs(xx, yy);
				}
			}
		if(flag){
			int kk = __gcd(u, d);
			u /= kk;
			d /= kk;
			printf("%d/%d\n", u, d);
		}
		else
			printf("0/1\n");

	}
	return 0;
}
