#include<bits/stdc++.h>
#define int long long
#define double long double
using namespace std;

const int MAXN = 1e6 + 10;
const int INF = 0x3f3f3f3f;

int cnt[50];
int pai[20];
std::vector<int> vec[20];

bool PDUI(int idx, int num) {
	if (cnt[idx] < num) return false;
	cnt[idx] -= num;
	return true;
}

void VDUI(int idx, int num) {
	cnt[idx] += num;
}

bool PSUN(int idx) {
	if (idx > 27) return false;
	if (idx % 9 == 0 || idx % 9 == 8) {
		return false;
	}
	if (cnt[idx + 1] && cnt[idx + 2]) {
		cnt[idx]--, cnt[idx + 1]--, cnt[idx + 2]--;
		return true;
	}
	return false;
}

void VSUN(int idx) {
	cnt[idx]++, cnt[idx + 1]++, cnt[idx + 2]++;
}

string idx_to_string(int idx) {
	string res;
	int t = idx % 9;
	if (t == 0) t = 9;
	res += t + '0';
	if (idx <= 9) res += 'w';
	else if (idx <= 18) res += 'b';
	else if (idx <= 27) res += 's';
	else res += 'z';
	return res;

}
int n;
bool judge(int num, bool tou, int start) {
	if (num == 0) return true;
	bool res = false;
	for (int idx = start; idx <= n; idx++) {
		int i = pai[idx];
		if (cnt[i] == 0) continue;

		if (PSUN(i)) {
			res = judge(num - 3, tou, i);
			VSUN(i);
			
		} 
		if (res) {
			return true;
		}
		if (tou == false && PDUI(i, 2)) {
			res = judge(num - 2, true, i);
			VDUI(i, 2);
		}
		if (res) {
			return true;
		}
		if (PDUI(i, 3)) {
			res = judge(num - 3, tou, i);
			VDUI(i, 3);
		}
		if (res) {
			return true;
		}
	}
	return res;
}
set<int> S;

void InsertPai(int idx) {
	int i;
	if (i = 1; i <= n; i++) {
		if (pai[i] > idx) break;
	}
	for (int j = n; j >= i; j--) {
		pai[j + 1] = pai[j];
	}
	n++;
}

void DeletePai(int idx) {
	int i;
	if (i = 1; i <= n; i++) {
		if (pai[i] == idx) break;
	}
	for (int j = i; j <= n; j++) {
		pai[j] = pai[j + 1];
	}
	n--;
}

signed main() {

	int T;
	cin >> T;
	while (T--) {
		for (int i = 1; i <= 34; i++) cnt[i] = 0;
		for (int i = 1; i <= 19; i++) vec[i].clear(), pai[i] = 0;
		S.clear();
		string s;
		cin >> s;
		for (int i = 0; i < s.length() - 1; i += 2) {
			int base;
			if (s[i + 1] == 'w') {
				base = 0;
			} else if (s[i + 1] == 'b') {
				base = 9;
			} else if (s[i + 1] == 's') {
				base = 18;
			} else {
				base = 27;
			}
			int t_idx = s[i] - '0';
			S.insert(base + t_idx);
			cnt[base + t_idx]++;
		}
		n = 0;
		for (auto c : S) {
			pai[++n] = c;
		}
		sort(pai + 1, pai + 1 + n);

		if (judge(14, false, 1)) {
			cout << "Tsumo!" << endl;
			continue;
		}
		int ans = 0;
		for (int i = 1; i <= n; i++) {
			cnt[i]--;
			int flag = 1;
			for (int j = 1; j <= 34; j++) {
				if (j > 27 && cnt[j] == 0) continue;
				if (S.cout(j) == 0) {
					InsertPai(j);
				}
				cnt[j]++;
				if (judge(14, false, 1)) {
					if (flag == 1) {
						ans++;
						flag = 0;
						vec[ans].push_back(i);
					}
					vec[ans].push_back(j);
				}
				cnt[j]--;
				if (S.cout(j) == 0) {
					DeletePai(j);
				}
			}
			cnt[i]++;
		}
		cout << ans << endl;
		for (int i = 1; i <= ans; i++) {
			cout << idx_to_string(vec[i][0]) << " ";
			for (int j = 1; j < vec[i].size(); j++) {
				cout << idx_to_string(vec[i][j]);
			}
			cout << endl;
		}
		
	}

}
