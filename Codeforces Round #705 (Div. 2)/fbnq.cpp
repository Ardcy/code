#include<bits/stdc++.h>
using namespace std;


using namespace std;
class Solution {
public:
    int reverse(int x) {
        int f = 0;
        if(x<0)f = -1;else f = 1;
        x = abs(x);
        long long int ans = 0;
        long long int base = 1;
        while(x){
            ans=ans * 10 + x%10;
            x/=10;
        }
        int p = x;
        cout << x << " " << p << endl;
        if(x != p )return 0;
        return f * ans;
    }
}P;

signed main(){
	cout <<  P.reverse(10) << endl;
}