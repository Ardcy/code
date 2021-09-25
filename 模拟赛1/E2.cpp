#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,k;
const int N = 2e5+5;
int arr[N];
stack<int>p1,p2;
int last[N];
void output(stack<int> P){
	stack<int>y;
	while(!P.empty()){
		y.push(P.top());
		P.pop();
	}
	while(!y.empty()){
		cout<<y.top()<<" ";y.pop();
	}cout<<endl;
}
signed main(){
	cin >> n >> k;
	for(int i=1;i<=n;i++){
		cin >> arr[i];
		last[arr[i]] = i;
	}
	set<int>st;
	for(int i=1;i<=n;i++){
		if(p1.empty()){
			p1.push(arr[i]);st.insert(arr[i]);continue;
		}
		while(1){
			int tp = p1.top();
			if(tp > arr[i] && last[tp] > i && st.count(arr[i])==0){
				st.erase(tp);p1.pop();
			}
			else{
				break;
			}
			if(p1.empty())break;
		}
		if(!st.count(arr[i])){
			p1.push(arr[i]);
		}
		st.insert(arr[i]);
	}
	output(p1);
}