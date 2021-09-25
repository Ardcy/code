#include<bits/stdc++.h>
using namespace std;
#define N 100010
#define M 1001

struct node{
	node *next;
	int where;
	double w;
}a[100001],*first[100001];
int cnt = 0;
void add(int x, int y, double z){
	cnt++;
	first[cnt]->where = y;
	first[cnt]->w = z;
	first[cnt]->next = &a[x];
	a[x] = *first[cnt];	
}
int main(){
	node *q;

	
	return 0;
}
