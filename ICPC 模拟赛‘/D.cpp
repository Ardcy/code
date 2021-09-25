#include <bits/stdc++.h>
#define int long long
using namespace std;

const int MAXN = 3000 + 10;

double dp[MAXN][MAXN];

signed main()
{
	int T;
	cin >> T;
	while(T--)
	{
		int hp1, hp2, w;
		double p;
		cin >> hp1 >> hp2 >> w >> p;
		for(int i = 0; i <= hp1; i++)
		{
			for(int j = 0; j <= hp2; j++)
			{
				if(i == 0 || j == 0)
				{
					dp[i][j] = 0;
				}
				else
				{
					dp[i][j] = 1.0 + p * dp[i][max(0ll, j - w)] + (1.0 - p) * dp[max(0ll, i - w)][j];
				}
			}
		}
		cout << fixed << setprecision(6) << dp[hp1][hp2] << endl;
	}
	return 0;
}
