#include<bits/stdc++.h>
using namespace std;
int main(){
	int a,b;
	cin>>a>>b;
	int ant = 0;
	while(a>0&&b>0){
		if(a>b)swap(a,b);
		b-=2;a+=1;ant++;
	}
	cout<<ant<<endl;
}
