#include<bits/stdc++.h>
using namespace std;
long long int count(long long int n){
    long long int s=1;
    for(long long int i=2;i*i<=n;i++){
        if(n%i==0){
            int a=0;
            while(n%i==0){
                n/=i;
                a++;
            }
            s=s*(a+1);
        }
    }
    if(n>1) s=s*2;
    return s;
}
int main(){
	long long int u;
	cin>>u;
	int h=0;
	while(u!=2){
		h++;
		u = count(u);
		
	}
    cout<<h<<endl; 
}




