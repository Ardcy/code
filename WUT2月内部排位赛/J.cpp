#include<bits/stdc++.h>
#define debug(x) cerr<<#x<<"="<<x<<endl
using namespace std;
#define int long long
map<string,int>p;
string q[100];
int a[25][8];
int aa[25][8];
int c[25][100];
signed main(){
	int cnt = 24;
	char s[5];
	for(int i=1;i<=24;i++){
		for(int j=1;j<=8;j++){
			scanf("%s",s);
			if(j==1){p[s]=i;a[i][j]=i;continue;}
			if(p.find(s)==p.end())p[s]=(++cnt),q[cnt]=s;
			a[i][j]=p[s],aa[i][j]=p[s];
		}
	}
	for(int i=1;i<=24;i++){
		for(int j=1;j<=7;j++){
			c[i][a[i][j+1]]=j;
		}
	}
	for(int i=1;i<=24;i++){
		for(int j=1;j<=7;j++){
			c[i][a[i][j+1]]=j;
		}
	}
	int t;
	cin>>t;
	char r[5],k[5];
	int num;
	while(t--){
		scanf("%s%s%d",&r,&k,&num);
		int L=p[r],R=p[k];
		for(int i=1;i<=num;i++){
			cin>>r;
			//debug(r);
			//cout<<q[p[r]]<<" ";
			int e = c[L][p[r]];
			int ff = a[R][e+1];
			cout<<q[ff]<<" ";
		}
		cout<<endl;
	}
	return 0;
}

/*
C 1 2 3 4 5 6 7

c 1 2 b3 4 5 b6 b7

#c #1 #2 3 #4 #5 6 7

bD b2 b3 4 b5 b6 b7 1

D 2 3 #4 5 6 7 #1

d 2 3 4 5 6 b7 1

be b3 4 b5 b6 b7 b1 b2

bE b3 4 5 b6 b7 1 2

E 3 #4 #5 6 7 #1 #2

e 3 #4 5 6 7 1 2

F 4 5 6 b7 1 2 3

f 4 5 b6 b7 1 b2 b3

#f #4 #5 6 7 #1 2 3

bG b5 b6 b7 b1 b2 b3 4

G 5 6 7 1 2 3 #4

g 5 6 b7 1 2 b3 4

#g #5 #6 7 #1 #2 3 #4

bA b6 b7 1 b2 b3 4 5

A 6 7 #1 2 3 #4 #5

a 6 7 1 2 3 4 5

bb b7 1 b2 b3 4 b5 b6

bB b7 1 2 b3 4 5 6

B 7 #1 #2 3 #4 #5 #6

b 7 #1 2 3 #4 5 6
1
bb F 5
b7 b2 b3 b5 1
*/
