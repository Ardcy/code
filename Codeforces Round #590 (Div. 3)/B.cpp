#include <iostream> 
#include <cstdio> 
#include <fstream> 
#include <algorithm> 
#include <cmath> 
#include <deque> 
#include <vector> 
#include <queue> 
#include <string> 
#include <cstring> 
#include <map> 
#include <stack> 
#include <set>
using namespace std;
deque<int>s1;
set<int>q;
signed main(){
	int n,k;
	cin>>n>>k;
	int a;
	for(int i=1;i<=n;i++){
		cin>>a;
		if(q.size()<k&&q.find(a)==q.end()){
			s1.push_front(a);
			q.insert(a);
		}
		if(q.size()==k&&q.find(a)==q.end()){
			int u = *s1.rbegin();
			s1.pop_back();
			q.erase(u);
			q.insert(a);
			s1.push_front(a);
		}
	}
	cout<<s1.size()<<endl;
	for(auto p:s1){
		cout<<p<<" ";
	}
	return 0;
}
