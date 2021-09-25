#include<bits/stdc++.h>
using namespace std;
#define N 200050
int a[N][26];
int b[26] = {0};
int main(){
    int k,n;
    cin>>n>>k;
    getchar();
    char c;
    for(int i=1;i<=n;i++){
        c = getchar();
        b[c-'a']++;
        a[b[c-'a']][c-'a']=i;
    }
    int ans = 0x3f3f3f3f;
    int ui = 0;
    for(int i=0;i<26;i++){
        for(int j = k;j<=b[i];j++){
            ans = min(ans,a[j][i]-a[j-k+1][i]+1);
        }
    }
    if(ans==0x3f3f3f3f)
    cout<<-1<<endl;
    else
    cout<<ans<<endl;
}
