#include<bits/stdc++.h>
using namespace std;
signed main(){
	string s;
	cin>>s;
	s="00"+s;
	int L=s.length();
	for(int i=0;i<L;i++){
		for(int j=i+1;j<L;j++){
			for(int k=j+1;k<L;k++){
				int n=(s[i]-'0')*100+(s[j]-'0')*10+s[k]-'0';
				if(n%8==0){
					cout<<"YES"<<endl;
					cout<<n;
					return 0;
				}
				
			}
		}
	}
	cout<<"NO"<<endl;
	return 0;
}
