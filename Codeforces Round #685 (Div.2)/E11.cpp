#include<bits/stdc++.h>
using namespace std;

int a[2000000];
signed main() {
	int n;
	cin>>n;

	cout<<"AND 1 2"<<endl;
	fflush(stdout);
	
	int AND1,OR1;
	cin>>AND1;
	cout<<"OR 1 2"<<endl;
	fflush(stdout);
	cin>>OR1;

	a[1] = 0;
	a[2] = OR1 - AND1;

	int AND2,OR2;
	cout<<"AND 1 3"<<endl;
	fflush(stdout);

	cin>>AND2;
	cout<<"OR 1 3"<<endl;
	fflush(stdout);
	cin>>OR2;

	a[3] = OR2 - AND2;

	for(int i = 4; i <= n; i++) {
		cout<<"XOR 1 "<<i<<endl;
		fflush(stdout);
		cin>>a[i];
	}

	int p = 0;
	cout<<"AND 2 "<<3<<endl;
	fflush(stdout);
	cin>>p;
	
	
	int ans_dis1 = 0;
	
	ans_dis1 = OR1 + AND1 + OR2 + AND2 - ( ( (OR1 - AND1 ) ^ ( OR2 - AND2) ) + p) - p;

	ans_dis1/=2;
	

	fflush(stdout);
	cout<<"!";
	for(int i=1;i<=n;i++){
		cout << " " << (a[i]^ans_dis1) ;
	}  cout<<endl;


}
