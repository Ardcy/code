#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[100]= {0};
int num = 0;
const int N = 6e5;
int summ[N]= {0};
int k=0;
string s;
signed main() {
    char c,t;
    cin>>s;
    for(int i=0;i<s.length();i++) {
    	c = s[i];
        if(c=='+')
            a[0]++;
        else
            a[c-'0']++;
    }
    for(int i=9; i>=1; i--) {
        for(int j=1; j<=a[i]; j++) {
            k++;
            t = (k-1)/(a[0]+1);
            if(num<t)
                num=t;
            summ[(k-1)/(a[0]+1)]+=i;
            while(summ[t]>=10) {
                summ[t]%=10;
                t++;
                summ[t]+=1;
                if(num<t)
                    num=t;
            }
        }
    }
    for(int i=num; i>=0; i--)
        printf("%lld",summ[i]);
    cout<<endl;
}
