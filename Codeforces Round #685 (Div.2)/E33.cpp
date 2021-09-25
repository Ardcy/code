#include<bits/stdc++.h>
using namespace std;
#define int long long
const int maxn = 2e5+10;
int arr[maxn];
set<int>P;
signed  main(){
	int k,l,r,t,x,y;
	cin>>k>>l>>r>>t>>x>>y;
	int p = k-l;
	int q = r-l;
	bool ans = true;
	if(p+y>q&&p<x){
		cout<<"No"<<endl;
		return 0;
	}
	if(y<=x){
		P.insert(p);
		while(t--){
			if(p+y<=q){
				p+=y;
			}
			if(P.count(p)){
				break;
			}
			P.insert(p);
			p-=x;
			if(P.count(p)){
				break;
			}
			P.insert(p);
			if(p<0){
				ans = false;
				break;
			}
			int num = p-q+y;
			int in = num/=x;
			p-=in*x;
			p+=in*y;
			t-=in;
			if(P.count(p)){
				break;
			}
			P.insert(p);
		}
		if(ans){
			cout<<"Yes"<<endl;
		}else{
			cout<<"No"<<endl;
		}	
		return 0;
	}
	if(x+y<=q){
		cout<<"Yes"<<endl;
		return 0;
	}else{
		P.insert(p);
		while(t--){
			if(p+y<=q){
				p+=y;
			}
			if(P.count(p)){
				break;
			}
			P.insert(p);
			p-=x;
			if(P.count(p)){
				break;
			}
			P.insert(p);
			if(p<0){
				ans = false;
				break;
			}
			int num = p-q+y;
			int in = num/=x;
			p-=in*x;
			p+=in*y;
			t-=in;
			if(P.count(p)){
				break;
			}
			P.insert(p);
		}
		if(ans){
			cout<<"Yes"<<endl;
		}else{
			cout<<"No"<<endl;
		}	
		return 0;	
	}
	if(ans){
		cout<<"Yes"<<endl;
	}else{
		cout<<"No"<<endl;
	}
	return 0;
}
