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
const int maxn = 2e5 +10;
const int mod = 1e9+7;
const int INF = 0x3f3f3f3f;
const double PI = acos(-1);
const double eps = 1e-6;

template<class T>
inline void read(T &res);

void yes(){ cout<<"YES"<<endl; }
void no(){ cout<<"NO"<<endl; }

void init(int n){
    for(int i = 1; i <= n; i++){
        
    }
}
int a[maxn], b[maxn];
map <int, int> mp;

bool is_mutex(int k) {
    for (int i = 2; i <= sqrt(k); i++) {
        if (k % i == 0 && k / i % 2 == 1) return true;
    }
    return false;
}
int get_sum(int n) {
    int res = 0;
    for (int i = 1; i <= n; i++) {
        if (is_mutex(a[i]))
            res+=2;
        else res+=1; 
    }
    return res;
}
signed main(){

    ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
    int T;
    cin >> T;
    while(T--) {
        int n, m, k;
        cin >> n;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
        }
        int ans = get_sum(n);
        if (ans % 2 == 0) {
            cout << "L" << endl;
        } else {
            cout << "W" << endl;
        }
    }
    return 0;
}

template<class T>
inline void read(T &res)
{
    char c;
    T flag=1;
    while((c=getchar())<'0'||c>'9')
        if(c=='-')flag=-1;res=c-'0';
    while((c=getchar())>='0'&&c<='9')
        res=res*10+c-'0';res*=flag;
}

