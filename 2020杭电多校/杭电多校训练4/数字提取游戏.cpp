#include<bits/stdc++.h>
using namespace std;
#define int long long
bool cmp(string a,string b){
	return a.length() == b.length()?a<b:a.length()<b.length();
}
signed main(){
	int n;
	cin >> n;
	vector<string>P;
	for(int i=1;i<=n;i++){
		string s;
		cin>> s;
		s+='a';
		string pre;
		for(int j=0;j<s.length();j++){
			pre = "";
			while(s[j]>='0'&&s[j]<='9'&&j<s.length()){
				if(pre.length()==0&&s[j]=='0'&&s[j+1]>='0'&&s[j+1]<='9'){
					j++;
					continue;
				}
				else {
					pre += s[j];
					j++;
				}
			}
			if(pre.length())P.push_back(pre);
		}	
	}
	sort(P.begin(),P.end(),cmp);
	for(int i=0;i<P.size() ;i++){
		cout << P[i] << "\n";
	}
}