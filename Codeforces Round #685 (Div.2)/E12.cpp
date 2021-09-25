#include <bits/stdc++.h>

int main() {

	int n;
	std::cin >> n;
	std::vector<int> x(n);
	x[0] = 0;
	int AND, OR;
	std::cout << "XOR 1 2" << std::endl;
	std::cin >> x[1];
//	std::cin >> AND;
//	std::cout << "OR 1 2" << std::endl;
//	std::cin >> OR;
//	x[1] = AND ^ OR;
	for (int i = 2; i < n; ++i) {
		std::cout << "XOR 1 " << i + 1 << std::endl;
		std::cin >> x[i];
	}

	std::vector<int> vis(n, -1);
	for (int i = 0; i < n; ++i) {
		if (vis[x[i]] != -1) {
			std::cout << "AND " << vis[x[i]] + 1 << " " << i + 1 << std::endl;
			int r;
			std::cin >> r;

			r ^= x[i];

			std::cout << "!";
			for (auto a : x) std::cout << " " << (a ^ r);
			std::cout << std::endl;
			return 0;
		}
		vis[x[i]] = i;
	}

	int p = vis[n - 1];


	if(p==1) {
		int e1,e2;
		std::cout << "AND " << 2 << " " << 3 << std::endl;
		std::cin>>e1;
	
		std::cout << "AND " << 1 << " " << 3 << std::endl;
		std::cin>>e2;
		
		int r;
		r = (e1 + e2) ^ x[2];
		std::cout << "!";
		for (auto a : x) std::cout << " " << (a ^ r);
		std::cout << std::endl;
	} else {
		std::cout << "AND 1 " << 2 << std::endl;
		std::cin>>AND;
		OR = AND + x[1];
		
		std::cout << "AND 2 " << p + 1 << std::endl;
		int k;
		std::cin >> k;
		int r = 0;
		r =  (AND + k) ^ ( OR - AND);
		std::cout << "!";
		for (auto a : x) std::cout << " " << (a ^ r);
		std::cout << std::endl;

	}

	return 0;
}
