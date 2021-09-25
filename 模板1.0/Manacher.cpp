#include<bits/stdc++.h>
using namespace std;
#define int long long
template <typename T>
vector<int> manacher(int n,const T&s){
	if(n==0){
		return vector<int>();
	}
	vector<int>res(2*n-1,0);
	int l=-1,r=-1;
	for(int z=0;z<2*n-1;z++){
		int i=(z+1)>>1;
		int j=z>>1;
		int p=(i>=r?0:min(r-i,res[2*(l+r)-z]));
		while(j+p+1<n&&i-p-1>=0){
			if(!(s[j+p+1]==s[i-p-1])){
				break;
			}
			p++;
		}
		if(j+p>r){
			l=i-p;r=j+p;
		}
		res[z]=p;
	}
	return res;
}
template <typename T>
vector<int> manacher(const T &s){
	return manacher((int) s.size(),s);
}
signed main(){
	string s;
	
	while(cin>>s){
		vector<int>res=manacher(s);
		for(auto P:res)cout<<P<<" ";
		cout<<endl;
		for(int i=0;i<s.length();i++){
			cout<<s[i]<<" # ";
		}
		cout<<endl;	
	}
	
	return 0;
}
/*
	abccba
	0 0 0 0 0 3 0 0 0 0 0  保存的是向左右扩张的最大值 
	a # b # c # c # b # a #
	aaaa
	0 1 1 2 1 1 0
	a # a # a # a #
	tasidhgna
	0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
	t # a # s # i # d # h # g # n # a #
	asdsaasd
	0 0 0 0 2 0 0 0 0 3 0 0 0 0 0
	a # s # d # s # a # a # s # d #
	dndndnd
	0 0 1 0 2 0 3 0 2 0 1 0 0
	d # n # d # n # d # n # d #
*/
