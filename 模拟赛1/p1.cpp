#include<bits/stdc++.h>
using namespace std;
#define int long long

const int N = 100;

string input;
int arr[N];
int brr[N];
int n;

string mul(int x){
	for(int i=0;i<=40;i++){
		arr[i] = brr[i] = 0;
	}
	int cnt = 0;
	//cout <<" mul " << x << endl;
	while(x){
		arr[cnt++] = x%10;
		x/=10;
	}
	//cout <<" mul " << x << endl;
	
	for(int i=0;i<=cnt;i++){
		for(int j=0;j<=cnt;j++){
			brr[i+j] += arr[i] * arr[j];
			brr[i+j] %= 10;
		}
	}
	string s;
	int p=0 ;
	for(int i=40;i>=0;i--){
		if(brr[i]){
			p = i;break;
		}
	}
	for(int i= p;i>=0;i--){
		s += ('0' + brr[i]);
	}
	return s;
}
int check(int mid){
	//cout<<" check " << mid <<endl;
	string s = mul(mid);
	//cout << " check " << s << endl;
	if(s.length() <= input.length() && s < input){
		return 1;
	}else if(s == input){
		return 0;
	}else{
		return -1;
	}
}
signed main(){
	int p;
	cin >> p;
	cout << mul(p) << endl;
}