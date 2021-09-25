#include<bits/stdc++.h>
using namespace std;
int main(){
    int a,b;
    cin>>a>>b;
    int c = (a+b);
    vector<int>P;
    if(c==0){
    	cout<<0<<endl;
    	return 0;
	}
    while(c){
        P.push_back((c)%1000);
        c/=1000;
    }
    int l = P.size();
    for(int i=l-1;i>=1;i--){
        if(i!=l-1){
			printf("%03d,",abs(P[i]));	
		}else
		cout<<(P[i])<<",";   
    }
    if(0!=l-1){
			printf("%03d\n",abs(P[0]));	
	}
	else cout<<(P[0])<<endl;
    
}
