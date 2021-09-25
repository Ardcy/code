#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod = 1e9 + 7;
const int maxn = 200500;
int ma = 3005;
double dp[ma][ma];
double sum[ma];
double arr[ma];
double ans = 0.0;
signed main()
{
    int N, M;
    cin >> N >> M;
    for (int i = 1; i <= N; i++) {
        cin >> arr[i];
    }

    
    sort(arr + 1, arr + N + 1);
    for (int i = 1; i <= N; i++) {
        sum[i] = sum[i - 1] + arr[i];
    }

    // dp[i][j] 表示 处理到第i块切糕结束时TinyTree还剩下j张优惠券的 Kiana的答案

    // 最后的答案就是 dp[n][0];

    // 所以第i块切糕是怎么分的呢？

    // 第i块切糕分成了两份 大的那份是x 小的那份是 arr[i]-x

    // 无论TinyTree怎么选 答案都是不变的

    // 所以 我们 可以 建立 等式

    // x + dp[N-i][j] = arr[i] - x + dp[i][j-1];

    // 表示 第i块切糕分成了两份 大的那份是x 小的那份是 arr[i]-x

    //
    // 好像做复杂了
    //
    //  重新定义dp[i][j]: dp[i][j] 表示 还剩下i块切糕时和j个优惠券的答案

    // 对于第 i+1 块切糕，有j张优惠券时的思考方式
    // Kiana 切成了合理的 两份
    // x 和 arr[i] - x
    // 选择了 x 就说明 Tiny 没有选， 还剩i块时 Tiny 依然有 j张券
    // x + dp[i][j] = arr[i] - x + dp[i][j-1];
    // dp[i+1][j] = x + dp[i][j];
    //

    // x = (arr[i] + dp[i][j-1] - dp[i][j])/2;
    // dp[i+1][j] = x + dp[i][j];

    // 这个式子说明了啥 还剩1块切糕的答案 可以推出两块的答案

    // 优先选择 拿小的

    //

    dp[0][0] = 0.0;
    for (int i = 1; i <= N; i++) {

        dp[i][min(i, M)] = sum[i] / 2;
        dp[i][0] = sum[i];

        for (int j = 1; j <= min(i,M); j++) {
            double x;
            x = (arr[i] + dp[i][j - 1] - dp[i][j]) / 2;
            if (x < 0) {
                dp[i + 1][j] = dp[i][j];
            } else
                dp[i + 1][j] = x + dp[i][j];
        }
    }
    cout << dp[N][M] << endl;
}
