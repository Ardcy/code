#include<bits/stdc++.h>
using namespace std;
const int N = 2e5+50;
int s[N][26];
char t[N];
int main() {
    cin>>t;
    int y = strlen(t);
    for(int i=1; i<=y; i++) {
        for(int j=0; j<=25; j++) {
            s[i][j] = s[i-1][j];
        }
        s[i][t[i-1]-'a']++;
    }
    int h = 0;
    cin>>h;
    while(h--) {
        int l,r;
        cin>>l>>r;
        int cnt=0;
        for(int i=0; i<=25; i++) {
            if(s[r][i]-s[l][i]>0)
                cnt++;
        }
        if(l==r||cnt>=3||t[l-1]!=t[r-1])
            cout<<"Yes"<<endl;
        else
            cout<<"No"<<endl;
    }
	return 0;
}
