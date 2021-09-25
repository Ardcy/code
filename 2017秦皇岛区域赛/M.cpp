#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

const int maxn = 2e5 + 10;

int a[maxn], vis[maxn];
queue<pair<int,int>> que;
int ans[maxn], idx, val;
string s;
void Bfs() {
	while(!que.empty()){
		int fi = que.front().first, se = que.front().second;
		que.pop();
		vis[fi] = 1;
		int next_id = a[fi];
		int next = s[next_id] - '0';
		if(ans[se] > s[fi] - '0') continue;
		if(vis[next_id] == 1) break;
		if(ans[se + 1] < next) {
			ans[se + 1] = next;
			idx = se + 1;
			val = next_id;
			que.push(make_pair(next_id, se + 1));
		}
	}
}
int main() {
	
	int T;
	cin >> T;
	int cast = 0;
	while(T--) {
		++cast;
		int n;
		cin >> n;
		cin >> s;
		while(!que.empty())
			que.pop();
		for(int i = 0; i < n; i++) {
			a[i] = (i * i + 1) % n;
			vis[i] = 0;
			ans[i] = 0;
		}
		int mx = 0;
		for(int i = 0; i < n; i++) {
			mx = max(mx, s[i] - '0');
		}
		ans[1] = mx; 
		for(int i = 0; i < n; i++) {
			if (mx == s[i] - '0'){
				que.push(make_pair(i,1));
				vis[i] = 1;
				idx = 1, val = i;
			}
		}
		Bfs();
		cout << "Case #" << cast << ": ";
		for(int i = 1; i <= idx; i++) {
			cout << ans[i];
		}
		for(int i = 1; i <= n-idx; i++){
			cout << s[a[val]];
			val = a[val];
		}
		cout << endl;
		
	}
	
	return 0;
}
