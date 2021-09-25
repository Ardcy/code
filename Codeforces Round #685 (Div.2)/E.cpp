#include<bits/stdc++.h>
const int N = 2e5+5;
int arr[N];
int q[N];
int main() {
	int n;
	std::cin>>n;
	std::cout<<"AND 1 2"<<std::endl;
	fflush(stdout);
	int p1,p2;
	std::cin>>p1;
	std::cout<<"OR 1 2"<<std::endl;
	fflush(stdout);
	std::cin>>p2;
	arr[2] = p2 - p1;
	int vis = 0;
	int a = 0;
	int f = 0;
	for(int i=3; i<=n; i++) {
		std::cout<<"XOR 1 "<<i<<std::endl;
		
		std::cin>>arr[i];
		
		fflush(stdout);
		if(q[arr[i]]!=0&&f==0) {
			f = 1;
			std::cout<<"AND 1 "<<i<<std::endl;
			fflush(stdout);
			std::cin>>a;
		}
		if(arr[i]==n-1) {
			vis = i;
				
		}
		q[arr[i]]=i;
	}

	if(f) {
		std::cout<<"! ";
		for(int i=1; i<=n; i++) {
			std::cout<<(a^arr[i])<<" ";
		}
		std::cout<<std::endl;
	} else {

		std::cout << "AND 2 " << vis << std::endl;
		int k;
		std::cin >> k;

		int r = 0;
		for (int i = 1; i < n; i *= 2) {
			if (~arr[1] & i) {
				r |= p1 & i;
			} else {
				r |= ~k & i;
			}
		}
		std::cout << "!";
		a = r;
		for(int i=1; i<=n; i++) {
			std::cout<<(a^arr[i])<<" ";
		}
		std::cout<<std::endl;
	}

}
