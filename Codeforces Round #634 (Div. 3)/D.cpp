#include<bits/stdc++.h>
using namespace std;
#define int long long
#define fi first
#define se second
#define inf INT_MAX
#define mp make_pair
char s[10][10];
signed main(){
	int t;
	cin>>t;
	while(t--){
		for(int i=1;i<=9;i++){
			cin>>(s[i]+1);
		}
		s[1][1]=s[1][2];
		s[2][4]=s[2][5];
		s[3][7]=s[3][8];
		s[4][2]=s[4][3];
		s[5][8]=s[5][9];
		s[6][6]=s[6][7];
		s[7][3]=s[7][4];
		s[8][5]=s[8][6];
		s[9][9]=s[9][8];
		for(int i=1;i<=9;i++){
			for(int j=1;j<=9;j++)cout<<s[i][j];cout<<endl;
		}
	}
	return 0;
}


