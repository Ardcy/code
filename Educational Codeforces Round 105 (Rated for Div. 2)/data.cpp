#include<bits/stdc++.h>
using namespace std;
signed main(){
	srand(time(0));
	cout << 1 << endl;


	int n = 1000;

	int m = 1000;

	//cout << n << " " << m << endl;
	vector<int>p;
	for(int i=1;i<=n;i++){
		int l = ((rand()<<15) + rand()) - ((rand()<<15) + rand());
		if(l)p.push_back(l);
		//cout << rand()%200 - 100 << " ";

	}//cout << endl;
	
	sort(p.begin(),p.end());p.erase(unique(p.begin(),p.end()),p.end());
	

	vector<int>q;
	for(int i=1;i<=m;i++){
		int l = ((rand()<<15) + rand()) - ((rand()<<15) + rand());
		if(l!=0)
		q.push_back(l);
		
	}
	
	sort(q.begin(),q.end());
	q.erase(unique(q.begin(),q.end()),q.end());
	cout << p.size() << " " << q.size() << endl;
	for(auto pp:p){
		cout << pp << " ";
	}cout << endl;
	for(auto qq:q){
		cout<<qq<<" ";
	}cout<<endl;
}