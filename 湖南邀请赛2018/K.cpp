#include<bits/stdc++.h>
#define int long long
#define sf(n) scanf("%lld",&n)
#define sff(a,b) scanf("%lld%lld",&a,&b)
#define sfff(a,b,c) scanf("%lld%lld%lld",&a,&b,&c)
#define debug printf("Here\n")
#define out(x) cout << x << endl
#define out2(x,y) cout << x << " " << y << endl
#define out3(x,y,z) cout << x << " " << y <<" " << z << endl
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second
#define SZ(x) ((int)(x).size())
using namespace std; 

inline int read(){
	int s = 0,w = 1;
	char ch = getchar();
	while(ch < '0'||ch > '9'){
		if(ch=='-')w = -1;
		ch = getchar();
	}
	while(ch >= '0'&&ch <='9'){
		s = s*10+ch - '0',ch = getchar();
	}
	return s*w;
} 
void yes(){cout << "YES" << endl;}
void no(){cout <<"NO" << endl;}

const int  MAXN = 2e5+10;
const int INF = 0x3f3f3f3f3f3f;
const int mod = 1e9+7;
const double eps = 1e-9;
const double PI = acos(-1.0);

int n;
int arr[MAXN];
int a[50];

bool judge1() {
	for (int i = 28; i <= 34; i++) {
		if (a[i] != 1) return false;
	}
	int ans = 0, flag = 1;
	for (int i = 0; i <= 18; i += 9) {
		if (a[i + 1] == 1) ans++;
		if (a[i + 9] == 1) ans++; 
		
		if (a[i + 1] == 2) {
			if (flag) ans += 2, flag = 0;
			else return false; 
		}
		
		if (a[i + 9] == 2) {
			if (flag) ans += 2, flag = 0;
			else return false; 
		}
//		cout << ans << endl;
	} 
	if (ans == 7) return true;
//	cout << ans << endl;
	return false;
}

bool judge2() {
	for (int i = 0; i < 3; i++) {
		for (int j = 1; j <= 9; j++) {
			a[i * 9 + j] --;
		}
		a[i * 9 + 1] -= 2;
		a[i * 9 + 9] -= 2;
		int flag = 1;
//		for (int j = 1; j <= 9; j++) {
//			cout << a[i * 9 + j] << " ";
//		}
//		cout << endl;
		for (int j = 1; j <= 9; j++) {
			if (a[i* 9 + j] != 0 && a[i * 9 + j] != 1) {
				flag = 0;
				break;
			}
			if (a[i * 9 + j] == 1) {
				flag = 2;
			}
		}
//		cout << flag << endl;
		if (flag == 2) return true;
	}
	return false;
}

signed main(){
	for (int i = 1; i <= 14; i++) {
		string s;
		cin >> s;
		if (s[0] >= '1' && s[0] <= '9') {
			int base = 0;
			if (s[1] == 'p') base = 9;
			else if (s[1] == 'w') base = 18;
			a[base + (s[0] - '0')]++;
		} else if(s[0] == 'd') {
			a[28]++;
		} else if(s[0] == 'n') {
			a[29]++;
		} else if(s[0] == 'x') {
			a[30]++;
		} else if(s[0] == 'b' && s[1] == 'e') {
			a[31]++;
		} else if(s[0] == 'z') {
			a[32]++;
		} else if(s[0] == 'f') {
			a[33]++;
		} else if(s[0] == 'b' && s[1] == 'a') {
			a[34]++;
		}
	}
//	for (int i = 1; i <= 34; i++) {
//		cout << a[i] << " ";
//	}
//	cout << endl;
	if (judge1()) {
		cout << "shisanyao!" << endl;
	} else if (judge2()) {
		cout << "jiulianbaodeng!" << endl;
	} else {
		cout << "I dont know!" << endl;
	}
}
// 1w 9w 1w 1s 9s 1p 9p dong nan xi bei zhong fa bai
// 1 0 0 0 0 0 0 0 1 1 0 0 0 0 0 0 0 1 2 0 0 0 0 0 0 0 1 1 1 1 2 1 1 0


