#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
const int N=3000005;
int T;
ull A,B,C;
ull f[N];
inline ull add(int m){
	ull sum=0;
	for(int j=1;j<=m;j++){
			int mm;
			cin>>mm;
			if(mm){
				sum+=f[j];
			}
		  }
		  return sum;
}
int main(){
	ios::sync_with_stdio();
	cin.tie(0);cout.tie(0);

	f[1]=1,f[2]=2;
	for(int i=3;i<N;i++){
		f[i]=f[i-1]+f[i-2];
         }
    cin>>T;
	for(int i=0;i<T;i++){
		int a,b,c;
	    cin>>a; 
		A=add(a);
		cin>>b;
		B=add(b);
		cin>>c;
		C=add(c);
		ull CC=A*B;
		int j;
		 for(j=1;C+f[j]!=CC;j++);
        printf("%d\n",j);
   }
   	return 0;
}
