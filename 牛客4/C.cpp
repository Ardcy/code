#include<bits/stdc++.h>
using namespace std;

int arr[10];
int brr[10];
int crr[10];
int drr[10];
int n,k;
int flag = 0;
void dfs(int x){
	if(x == k+1){
		for(int i=1;i<=n;i++)drr[i] = 0;
		set<int>p;
		for(int i=1;i<=k;i++){
			p.insert(crr[i]);
		}
		if(p.size()!=k)return ;
		for(int i=1;i<=k;i++){
			drr[crr[i]] += brr[i];
		}

		int flag1 = 1;
		for(int i=1;i<=n;i++){
			//cout << drr[i] << " ";
			if(drr[i] > arr[i]){
				flag1 = 0;
			}
		}//cout << endl;
		if(flag1)flag = 1;
		return;
	}
	for(int i=1;i<=n;i++){
		crr[x] = i;
		dfs(x+1);
		if(flag)return;
	}
}
signed main(){
	
	cin>> n >> k;
	for(int i=1;i<=n;i++){
		cin >> arr[i];
	}
	for(int i=1;i<=k;i++){
		cin >> brr[i];
	}
	dfs(1);
	if(flag==1){
		for(int i=1;i<=n;i++)cout << crr[i] << " ";cout << endl;
	}
	else{
		cout << "-1" << endl;
	}
}