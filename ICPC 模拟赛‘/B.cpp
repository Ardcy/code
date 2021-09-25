#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main()
{
	int x, y, a, b;
	cin >> x >> y >> a >> b;
	if((a == 1 && b == y) || (a == x && b == 1))
	{
		cout << 1 << endl;
	}
	else
	{
		cout << 2 << endl;
	}
	return 0;
}
