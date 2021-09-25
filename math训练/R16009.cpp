#include<bits/stdc++.h>
using namespace std;
signed main()
{
  int n;
  cin >> n;
  if (n < 4) {
    printf("NO\n");
    return 0;
  }
  printf("YES\n");
  while (n > 5) {
    printf("%d - %d = %d\n", n, n-1, 1);
    printf("%d * %d = %d\n", 1, 1, 1);
    n -= 2;
  }
  if (n == 4) {
    printf("1 * 2 = 2\n");
    printf("2 * 3 = 6\n");
    printf("6 * 4 = 24\n");
  } else {
    printf("3 + 4 = 7\n");
    printf("7 + 5 = 12\n");
    printf("1 * 2 = 2\n");
    printf("2 * 12 = 24\n");
  }
  return 0;
}
