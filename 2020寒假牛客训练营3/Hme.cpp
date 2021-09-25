#include<bits/stdc++.h>
using namespace std;
string a;
long long int n,k;
int main(){
	cin>>n>>k>>a;
	long long int ans = 0;
	long long int j=0;
	long long int num = 0;
	for(long long int i=0;i<a.length();i++){
		if(a[i]!='1'){
			num++;
		}
		while(num>k){
 			if(a[j]!='1')num--;
 			j++;
		}
		ans = max(ans,i-j+1);
	}
	long long int ans1 = 0;
	for(long long int i=0;i<a.length();i++){
		if(a[i]!='0'){
			num++;
		}
		while(num>k){
 			if(a[j]!='0')num--;
 			j++;
		}
		ans1 = max(ans1,i-j+1);
	}	
	cout<<(ans>n?n:max(ans,ans1));
}
