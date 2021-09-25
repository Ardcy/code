#include<bits/stdc++.h>
using namespace std;
struct node{
	node *next;
	int where;	
}a[100001],*f[100001];
int cnt = 0;
void add(int x,int y){
	cnt++;
	cout<<1<<endl;
	f[cnt]->where = y;
	cout<<1<<endl;
	f[cnt]->next = &a[x];
	cout<<1<<endl;
	a[x] = *f[cnt];
}
int main(){
	add(0,1);
}
