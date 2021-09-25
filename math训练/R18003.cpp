#include<bits/stdc++.h>
using namespace std;
#define int long long
struct node{
	int x,y;
}e[205000];
bool cmp(node a,node b){
	return a.x<b.x;
}
signed main(){
	int n;
	cin>>n;
	int ans1 = 1;
	for(int i=1;i<=2*n;i++){
		cin>>e[i].x;
		e[i].y = i%n;
		if(i%n==0)e[i].y=n;
	}
	int m;
	cin>>m;
	sort(e+1,e+2*n+1,cmp);
	for(int i=1;i<=2*n;i++){
		int cnt = 1;
		vector<int>v;
		v.push_back(e[i].y); 
		while(e[i+1].x==e[i].x){
			i++;
			cnt++;
			v.push_back(e[i].y); 
		}
		sort(v.begin(),v.end());
		int k = 0;
		for(int i=1;i<v.size();i++){
			if(v[i]==v[i-1])k++;
		}
		int ans2 = 1;
		for(int i=1;i<=v.size();i++){
			
			if(i%2==0&&k){
				ans2*=(i/2);
				ans2%=m;
				k--;
			}
			else{
				ans2*=i;
				ans2%=m;	
			}	
		}
		ans1*=ans2;
		ans1%=m;
	}
	cout<<ans1<<endl;
	return 0;
}
