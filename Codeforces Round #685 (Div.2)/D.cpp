#include<bits/stdc++.h>
using namespace std;
#define int long long 
const int N = 2e5+5;
int arr[N];
const int mod = 1e9+7;
int qp(int a,int b){
	int ans = 1;
	while(b){
		if(b&1){
			ans *= a,ans%=mod;
		}
		a*=a,a%=mod;
		b>>=1;
	}
	return ans;
}
int d,k;
const double eps = 1e-7;
bool solve(){
    for(int i = d/k; i >= 0; i--) {
        int t = d * d - i * k * i * k;;
        int b = (int)sqrt(t);
        int cnt1 = i, cnt2 = b / k;
        if ((i + (int)sqrt(t)/k) % 2 == 0) {
            if(i == (int)sqrt(t)/k) {
                return false;
            }
        } else {
            if(abs(i - (int)sqrt(t)/k) <= 1) {
                return true;
            }
        }
    }
}
signed main(){
	int t = 100000;
	cin>>t;
	while(t--){
		cin>>d>>k;

		if(!solve()){
			cout<<"Utkarsh"<<endl;
		}else{
			cout<<"Ashish"<<endl;
		}
	}
} 
