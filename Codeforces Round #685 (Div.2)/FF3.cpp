#include<bits/stdc++.h>
using namespace std;

char a[6000][2000];
set<int>P;
string str[16] = {"0000","0001","0010","0011","0100","0101","0110","0111","1000","1001","1010","1011","1100","1101","1110","1111"};
signed main(){
	int n;
	cin >> n;
	for(int i=2;i<=sqrt(n);i++){
		if(n%i==0){
			P.insert(i);
			P.insert(n/i);
		}
	}
	getchar();
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n/4;j++){
			a[i][j] = getchar();
		}
		getchar();
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n/4;j++){
			
			for(auto p:P){
				if()
			}
		}
	}
	
	
}
