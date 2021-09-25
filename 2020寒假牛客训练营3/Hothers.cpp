#include <bits/stdc++.h>
using namespace std;
long long int n,k;
string a;
long long int answer(char x){
    long long int len=a.length();
    long long int ans=0,j=0,num=0;
    for(long long int  i=0;i<len;i++){
        if(a[i]!=x){
            num++;
            while(num>k){
                if(a[j]!=x) num--;
                j++;
            }
        }
        ans=max(ans,i-j+1);
    }
    return ans;
}
int main(){
    long long int ans;
    cin>>n>>k>>a;
    cout<<" "<<(a.length())<<endl;
    ans=max(answer('1'),answer('0'));
    if(ans>n) ans=n;
    cout<<ans;
    return 0;
}
