#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,k;
	cin >> n >> k;
	if(n == 0){
		cout << "Austin" << endl;
		return 0;
	}
	if(k==1){
		if(n&1){
			cout << "Adrien" << endl;
		}else{
			cout << "Austin" << endl;
		}
	}else if(k>=2){
		cout << "Adrien" << endl;
	}
}