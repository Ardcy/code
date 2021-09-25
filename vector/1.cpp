#include<bits/stdc++.h>
using namespace std;
#define int long long
vector<int> a;
signed main(){
	a.push_back(1);
	cout<<a[0]<<endl;
	for(auto it=a.begin();it!=a.end();it++){
		cout<<*it<<endl;
	}
	cout<<a.size()<<endl;
	a.pop_back();
	cout<<a.size()<<endl;
	a.push_back(12);a.push_back(13);
	cout<<"aµÄÈÝÁ¿ÊÇ"<<a.capacity()<<endl;
	for(auto it=a.rbegin();it!=a.rend();it++) 
	cout<<*it<<" ";
	cout<<endl;
	cout<<a.empty()<<endl;
	sort(a.rbegin(),a.rend());
	for(auto it=a.begin();it!=a.end();it++)
	cout<<*it<<" ";
	cout<<endl;
	a.push_back(45);
	for(auto it=a.begin();it!=a.end();it++){
		it++;
		cout<<*it;
		cout<<endl;
		it--;
		cout<<*it<<endl;
	}
	return 0;
}
