#include<bits/stdc++.h>
using namespace std;
#define N 210
#define Mod 31011
int n, m;
struct Edge {
	int f,t,len;
	void read() {
		scanf("%d%d%d", &f, &t, &len);
	}
	bool operator < (const Edge &B) const {
		return len < B.len;
	}
}E[5050];
map<int, int> M;
int root[N], tmp[N];
void reset() {
	for(int i = 1; i <= n; ++i)
		root[i] = i;
}
int find(int x) {
	if(x!=root[x])root[x]=find(root[x]);
	return root[x];
}
int count(int x) {
	int res = 0;
	while(x)res+=x&1,x>>=1;
	return res;
}

int main() {
	map<double,int>P;
	P[1.2]=1;
	cout<<P[1.2];
	scanf("%d%d", &n, &m);
	int i, j, k;
	for(i = 1; i <= m; ++i)
		E[i].read();
	sort(E + 1, E + m + 1);
	int intree = 0, ra, rb;
	reset();
	for(i = 1; i <= m; ++i) {
		ra = find(E[i].f);
		rb = find(E[i].t);
		if (ra != rb) {
			++M[E[i].len];
			root[ra] = rb;
			if (++intree == n - 1)
				break;
		}
	}
	if (intree < n - 1) {puts("0");return 0;}
	int S, res = 1, now;
	reset();
	for(i = 1; i <= m; i=j+1) {
		for(j = i; E[j].len == E[j + 1].len; ++j);
		if (M[E[i].len]) {
			memcpy(tmp, root, sizeof root);
			now = 0;
			for(S = 1; S < (1 << (j - i + 1)); ++S) {
				if (count(S) != M[E[i].len])
					continue;
				memcpy(root, tmp, sizeof tmp);
				bool ac = 1;
				for(k = i; k <= j; ++k) {
					if ((S >> (k - i)) & 1) {
						ra = find(E[k].f);
						rb = find(E[k].t);
						if (ra == rb) {
							ac = 0;
							break;
						}
						root[ra] = rb;
					}
				}
				now+=ac;
			}
			res = res * now % Mod;
			memcpy(root, tmp, sizeof tmp);
			for(k = i; k <= j; ++k) {
				root[find(E[k].f)]=find(E[k].t);
			}
		}	
	}
	printf("%d", res);
	return 0;
}

