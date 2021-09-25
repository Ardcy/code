#include<bits/stdc++.h>
using namespace std;
int a[100050];
struct node{
	int a1,a2,a3,a4;
}e[100050];
bool cmp(node a,node b){
	return a.a1<b.a1;
}
int main(){
	int n;
	cin>>n;
	int cnt = 0;
	int root=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]>0)cnt++;
		if(cnt==1&&!root)root=i;
	}
	printf("The size of the tree is %d\n",cnt);
	printf("Node %d is the root node of the tree\n",a[root]);
	 cnt = 0;
	for(int i=1;i<=n;i++){
		if(a[i]>0)cnt++;
		int father,l,r;
		if(i/2>=1)father = a[i/2];else father = -1; 
		if(i*2<=n)l = a[i*2];else l =-1;
		if(i*2+1<=n)r = a[i*2+1];else r = -1;
		
		
		if(a[i]>0){
			e[cnt].a1=a[i];e[cnt].a2=father;e[cnt].a3=l;e[cnt].a4=r;
			
		}
	}
	sort(e+1,e+cnt+1,cmp);
	for(int i=1;i<=cnt;i++){
		printf("The father of node %d is %d, the left child is %d, and the right child is %d\n",e[i].a1,e[i].a2,e[i].a3,e[i].a4);
	}
}


