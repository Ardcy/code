#include<bits/stdc++.h>
using namespace std;
const int N = 20;
vector<int>P[N];

int ru[N];
int n;
void lay_dfs(int head) {

	queue<int>P1;
	vector<int>Q;
	Q.push_back(head);
	P1.push(head);
	int cnt = 1;
	while(!P1.empty()) {
		int y = P1.front();
		P1.pop();
		for(auto p:P[y]) {
			if(p!=-1)P1.push(p),Q.push_back(p);
		}

	}
	for(int i=0; i<n; i++) {
		if(i!=n-1)cout<<Q[i]<<" ";
		else cout<<Q[i]<<endl;
	}


}
vector<int>P2;
void in_dfs(int head) {

	if(head==-1)return;

	in_dfs(P[head][0]);
	P2.push_back(head);
	in_dfs(P[head][1]);
}
signed main() {

	cin>>n;
	getchar();
	for(int i=0; i<n; i++) {
		char a,b;
		scanf("%c %c",&a,&b);
		if(i!=n)getchar();
		if(b=='-') {
			P[i].push_back(-1);
		} else {
			P[i].push_back(b-'0');
			ru[b-'0']++;
		}
		if(a=='-') {
			P[i].push_back(-1);
		} else {
			P[i].push_back(a-'0');
			ru[a-'0']++;
		}
	}
	int head = -1;
	for(int i=0; i<n; i++) {
		//cout<<ru[i]<<endl;
		if(ru[i]==0)head=i;
	}
	//cout<<head<<endl;
	lay_dfs(head);
	in_dfs(head);
	for(int i=0; i<n; i++) {
		if(i!=n-1)cout<<P2[i]<<" ";
		else cout<<P2[i]<<endl;
	}

}
