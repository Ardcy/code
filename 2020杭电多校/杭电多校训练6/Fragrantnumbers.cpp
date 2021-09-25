#include<bits/stdc++.h>
using namespace std;

const int N = 5005;
int ans[100*N];

set<int>Num[N];
string s;


signed main(){
	s = "0";
	for(int i=1;i;i++){
		s += "1145141919";
		if(s.length() >= 20)break;
	}
	Num[0].insert(0);
	Num[1].insert(1);
	
	for(int i=2;i<s.length();i++){

		for(int j=max(0,i-4);j<i;j++){
			
			int y = 0;
			int base = 1;
			for(int w=i;w>=j+1;w--){
				y += base*(s[w]-'0');
				base *= 10;
			}
			for(auto p:Num[j]){

				if(y+p<5001 && y+p >0)
				Num[i].insert(y+p);
				if(y*p<5001 && y*p > 0)
				Num[i].insert(y*p);
			}
			
		}
	}

	// cout <<"-----------" << endl;

	// for(int i=1;i<=50;i++){
	// 	cout << "<<" << i << ">> 的 答案是" << Num[i].size() << endl; 
	// }
	set<int>R;
	int flag = 0;
	for(int i=1;i<s.length();i++){
		//cout << Num[i].size() << endl;
		for(auto p:Num[i]){
			//cout << p << " ";
			if(ans[p]==0){
				ans[p] = i;
				R.insert(p);
				if(R.size()>5000){
					break;
					flag = 1;
				}
			}
		}//cout << endl;
		if(flag)break;
	}

	//cout << R.size() << endl;
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		if(ans[n])
		cout << ans[n] << endl;
		else{
			cout << -1 << endl;
		}
	}
}