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
using namespace std;
#define int long long
const int maxn = 2e3 +10;
array <int,maxn> a,sum;
string s[10]={ "1110111", "0010010", "1011101", "1011011", "0111010", "1101011", "1101111", "1010010", "1111111", "1111011"};
string s2[maxn];
void cal(string &str,int k){
    a[k] = 10;
    for(int i=0;i<10;i++){
        int temp = 0;
        for(int j=0;j<7;j++){
            if(s[i][j] == str[j] );
            else if(s[i][j] == '1' && str[j] == '0') temp++;
            else{
                temp = 10;
                break;
            }
        }
        a[k] = min(a[k],temp);
    }
}
int n,kk;
int cal_max(string &str,int k){
    int m = kk - sum[k+1];
    
    for(int i=9;i>=0;i--){
        int temp = 0;
        for(int j=0;j<7;j++){
            if(s[i][j] == str[j] );
            else if(s[i][j] == '1' && str[j] == '0') temp++;
            else{
                temp = 10;
                break;
            }
        }
        if(temp!=10 && m>=temp){
            kk -= temp;
            for(int j=0;j<7;j++) str[j] = s[i][j];
            return i;
        }
    }
}
int to_max(string &str,int k){
    int ans = 0,l = 0;
    for(int i=9;i>=0;i--){
        int temp = 0;
        for(int j=0;j<7;j++){
            if(s[i][j] == str[j] );
            else if(s[i][j] == '1' && str[j] == '0') temp++;
            else{
                temp = 0;
                break;
            }
    	}
        if(ans<temp && kk>=temp){
            ans = temp;
            l = i;
        }
    }
    kk -= ans;
    return l;
}

signed main(){
    cin>>n>>kk;   
    for(int i=1;i<=n;i++){
        cin>>s2[i];
        cal(s2[i],i);
        cout<<a[i]<<endl;//最小要加 
    }
    for(int i=n;i>=1;i--){
        sum [i] = sum[i+1] + a[i];
    }
    if(sum[1]>kk) cout<<-1<<endl;
    else{
        string ans="";
        for(int i=1;i<=n;i++){
            ans += cal_max(s2[i],i)+'0';
           // cout<<ans<<endl;
        }
        if(kk>0){
            for(int i=n;i>=1;i--){
                ans[i-1] = to_max(s2[i],i) +'0';
                if(kk == 0) break;
            }
        }
        if(kk>0) cout<<-1<<endl;
        else cout<<ans<<endl;
    }
    return 0;
}
