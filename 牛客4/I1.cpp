#include <iostream>
#include <string>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <stack>
#include <map>
#include <queue>
#include <set>
#include <vector>
#include <array>
#include <cstring>
#include <unordered_map>
using namespace std;
#define int long long
#define double long double
const int maxn = 1e6 + 10;
const int mod = 1e14 + 13;
const int base = 37977;
const int INF = 0x3f3f3f3f;
const double PI = acos(-1);
const double eps = 1e-6;

template<class T>
inline void read(T &res);

void yes(){ cout << "YES" << endl; }
void no(){ cout << "NO" << endl; }

void init(int n){
    for(int i = 1; i <= n; i++){
        
    }
}
int Hash[maxn], Next[maxn], str[maxn], Base[maxn];

void getNext(int n) {
	for(int i = 2,j = 0; i <= n; i++){
		while(j > 0 && str[i] != str[j+1]) j = Next[j];
		if(str[i] == str[j+1]) j++;
		Next[i] = j;
	}
}
int getHash(int l, int r) {
    int res = ((Hash[r] - Hash[l - 1] * Base[r - l + 1]) % mod + mod) % mod;
    return res;
}
const int mod1 = 1e9+7,base1 = 38295;
int Hash1[maxn],Base1[maxn];
int getHash1(int l, int r) {
    int res = ((Hash1[r] - Hash1[l - 1] * Base1[r - l + 1]) % mod1 + mod1) % mod1;
    return res;
}
signed main(){

    ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> str[n - i + 1];
    }
    getNext(n);
    Base[0] = 1;Base1[0] = 1;
    for (int i = 1; i <= n; i++) {
        Hash[i] = base * Hash[i - 1] + str[i];
        Hash[i] %= mod;
        Base[i] = Base[i - 1] * base;
        Base[i] %= mod;
        Hash1[i] = base1 * Hash1[i - 1] + str[i];
        Hash1[i] %= mod1;
        Base1[i] = Base1[i - 1] * base1;
        Base1[i] %= mod1;
    }
    int ans = n + 1, ans1, ans2;
    for (int i = 1; i <= n; i++) {
        int len = i - Next[i];
        if (i % len == 0) {
            if (getHash(1, i - len) == getHash(len + 1, i) && getHash1(1, i - len) == getHash1(len + 1, i)) {
                int j = 0;
                while (str[++i] == str[++j] && i <= n);
                i--;
                int temp = len + n - i;
                if (temp < ans) {
                    ans = temp;
                    ans1 = n - i;
                    ans2 = len;
                }
            }
        }
    }
    cout << ans1 << " " << ans2 << endl;
    return 0;
}

template<class T>
inline void read(T &res)
{
    char c;
    T flag = 1;
    while((c = getchar()) < '0'|| c > '9')
        if (c == '-') flag = -1; res = c - '0';
    while((c = getchar()) >= '0' && c <= '9')
        res = res * 10 + c - '0'; res *= flag;
}