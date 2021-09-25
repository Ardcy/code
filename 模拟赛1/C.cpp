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
	
	int r = 42724693;
	cout<< mul(r)<<endl;
	// for(int i=1;i<=10000;i++){
	// 	cout << mul(i) << endl;
	// }
	cin >> input;
	//cout << input << endl;
	//
	//

	int l = 0,r = 1e14;
	int mid,flag;
	int ans = -1;
	while(l <= r){
		mid = (l+r)/2;
		flag = check(mid);
		if(flag == 1){
			l = mid+1;
		}
		if(flag == 0){
			ans = mid;
			break; 
		}
		if(flag == -1){
			r = mid-1;
		}

		//cout << mid << endl;
	}
	for(int i=max(l-1000000,1ll);i<=l+1000000 ;i++){
		if(check(i)==0){
			ans = i;break;
		}
	}
	cout<< ans << endl;
}