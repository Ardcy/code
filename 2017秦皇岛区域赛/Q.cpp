#include<bits/stdc++.h>
using namespace std;
const int N = 2e7+5;
int vis[N];
int pri[N];

int get_prime() {
	int cnt = 0;
	
	for(int i=2; i<=N; i++) {
		if(!vis[i]) {
			
			pri[cnt++] = i;
			for(int j=2*i ; j<=N; j+=i){
				vis[j] = 1;
			}
		}
	}
}
signed main() {
	get_prime();
	for(int i=0;i<=100000;i++){
		if(pri[i]==pri[i+1]-2&&pri[i+1]+2==pri[i+2]){
			cout<<pri[i]<<" "<<pri[i+1]<<" "<<pri[i+2]<<endl;
		}
		
	}
}
