#include<bits/stdc++.h>
using namespace std;

int main() {
    int U[405000]={0};
    long long int T,x;
    cin>>T>>x;
    int d=0,e;
    while(T--) {
    	cin>>e;
    	U[e%x]++;
    	while(U[d%x]>d/x){
			d++; 
		}
		 cout<<d<<endl;
		
    }
}
