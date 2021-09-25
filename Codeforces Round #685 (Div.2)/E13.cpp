#include<bits/stdc++.h>
using namespace std;
int dx[] = {9,6,12,15,5,14,0,2,8,7,10,11,1,4,13,3};

signed main(){
	cout << (dx[0] & dx[1]) <<endl;
	cout << (dx[0] | dx[1]) <<endl;
	for(int i=2;i<16;i++){
		cout<< ( dx[0] ^ dx[i] ) << endl;
	}
}
