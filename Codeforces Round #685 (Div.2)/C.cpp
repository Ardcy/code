#include<bits/stdc++.h>
using namespace std;
#define int long long 
const int N = 2e5+5;
int arr[N];
const int mod = 1e9+7;
int adp[30],bdp[30];

signed main(){
	int t;
	cin>>t;
	while(t--){
		int n,k;
		cin>>n>>k;
		string a,b;
		cin>>a>>b;
		for(int i=0;i<30;i++){
			adp[i] = 0;
			bdp[i] = 0;
		}
		for(int i=0;i < n;i++){
			adp[a[i]-'a']++;
			bdp[b[i]-'a']++;
		}
		int f = 1;
		int cnt = 0;
		
		for(int i=0;i<26;i++){
			if(adp[i] == bdp[i]){
				continue;
			}
			else{
				if(adp[i] > bdp[i]){
					if((adp[i] - bdp[i] )%k==0){
						cnt+= (adp[i] - bdp[i] )/k;
					}
					else {
						f = 0;break;
					}
				}
				else{
					if(( -adp[i] + bdp[i] )%k==0){
						cnt -= (-adp[i] + bdp[i] )/k;
					}
					else {
						f = 0;break;
					}
					if(cnt<0){
						f = 0;
						break;
					}
					
				}
				
			}
		}
		
		if(f){
			cout<<"Yes"<<endl;
		}else cout<<"No"<<endl;
	}
} 
