#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e5+5;
int arr[N];
stack<int>p1,p2;
int n,k;
int last[N];
bool f[N];
signed main(){
	cin >> n >> k;
	for(int i=1;i<=n;i++){
		cin >> arr[i];
		last[arr[i]] = i;
	}
	p1.push(arr[1]);
	f[arr[1]]=true;

	for(int i=2;i<=n;i++){

		int minr = 100000000;
		int to = p1.top();
		int flag = 0;
		while(to != arr[i]){
			if( i > last[to] && to > arr[i]){
				break;
				flag = 1;
			}else{
				p2.push(to);
				minr = min(minr,to);
				f[to] = false;
				p1.pop();
				if(p1.empty()){
					break;
				}
				to = p1.top();
			}
		}

		if(flag){
			while(!p2.empty()){
				p1.push(p2.top());
				f[p2.top()] = true;
				p2.pop();
			}
		}else{
			while(!p2.empty()){
				if(p2.top()<arr[i]){

					p1.push(p2.top());
					f[p2.top()] = true;
				}
				p2.pop();
			}
			cout<<"to = "<<to <<endl;
			if(!f[arr[i]]){
				p1.push(arr[i]);
				f[arr[i]] = true;	
			}
			
		}

		cout<< " i = " << i << " p1.size() = " << p1.size() << endl;
		cout << p1.top() << endl;
	}
	while(!p1.empty()){
		//cout<<p1.top()<<" ";
		p2.push(p1.top());
		p1.pop();
	}
	while(!p2.empty()){
		cout<<p2.top()<<" ";
		//p2.push(p2.top());
		p2.pop();
	}cout<<endl;
}