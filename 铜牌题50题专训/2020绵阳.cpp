#include<bits/stdc++.h>
using namespace std;

signed main(){
	int t;
	cin >> t;
	int d = 3;
	for(int i=1;i<=t;i++){
		int n;
		cin >> n;
		if(n==3||n==4||n==2||n==6){
			printf("Case #%d: -1\n",i);
			continue;
		}
		if(n&1){
			printf("Case #%d: 1\n",i);
		}else{

			if((n/2)%2==0){
				printf("Case #%d: 2\n",i);
				continue;
			}

			if((n%3)==0){
				printf("Case #%d: 2\n",i);
			}else{
				printf("Case #%d: 3\n",i);
			}
		}
	}
}
