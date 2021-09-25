#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e5+5;
int arr[N];
stack<int>p1,p2;
int fir[N];
int last[N];
signed main(){
	int n,k;
	cin >> n >> k;
	for(int i=1;i<=n;i++){
		fir[i] = last[i] = 0;
	}
	for(int i=1;i<=n;i++){
		cin >> arr[i];
		// if(fir[arr[i]]==0){
		// 	fir[arr[i]] = i;
		// }
		last[arr[i]] = i;
	}
	for(int i=1;i<=n;i++){
		// 不在 栈里 或者 栈为空
		// push  并 标记为位置
		if(p1.empty()){
			p1.push(arr[i]);
			fir[arr[i]] = i;
			continue;
		}
		else if(fir[arr[i]]==0){

			

			
			continue;
		}
		cout<< " i = " << i << " p1.size() = " << p1.size() << endl;
		int to = p1.top();
		while(!p2.empty())p2.pop();
		while( to != arr[i] ){
			if(to < arr[i]){
				p2.push(to);
				p1.pop();
				to = p1.top();
			}
			else {
				if(i > last[to]){
					break;
				}else{
					p2.push(to);
					p1.pop();
					to = p1.top();			
				}
			}


		}
		int tp;
		if(to != arr[i]){
			while(!p2.empty()){
				tp = p2.top();
				p1.push(tp);
				p2.pop();
			}
		}else{
			p1.pop();
			while(!p2.empty()){
				tp = p2.top();
				p1.push(tp);
				p2.pop();
			}
			p1.push(to);
		}

		cout<< " i = " << i << " p1.size() = " << p1.size() << endl;
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