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

    // dp[i][j] ��ʾ ������i���и����ʱTinyTree��ʣ��j���Ż�ȯ�� Kiana�Ĵ�

    // ���Ĵ𰸾��� dp[n][0];

    // ���Ե�i���и�����ô�ֵ��أ�

    // ��i���и�ֳ������� ����Ƿ���x С���Ƿ��� arr[i]-x

    // ����TinyTree��ôѡ �𰸶��ǲ����

    // ���� ���� ���� ���� ��ʽ

    // x + dp[N-i][j] = arr[i] - x + dp[i][j-1];

    // ��ʾ ��i���и�ֳ������� ����Ƿ���x С���Ƿ��� arr[i]-x

    //
    // ������������
    //
    //  ���¶���dp[i][j]: dp[i][j] ��ʾ ��ʣ��i���и�ʱ��j���Ż�ȯ�Ĵ�

    // ���ڵ� i+1 ���и⣬��j���Ż�ȯʱ��˼����ʽ
    // Kiana �г��˺���� ����
    // x �� arr[i] - x
    // ѡ���� x ��˵�� Tiny û��ѡ�� ��ʣi��ʱ Tiny ��Ȼ�� j��ȯ
    // x + dp[i][j] = arr[i] - x + dp[i][j-1];
    // dp[i+1][j] = x + dp[i][j];
    //

    // x = (arr[i] + dp[i][j-1] - dp[i][j])/2;
    // dp[i+1][j] = x + dp[i][j];

    // ���ʽ��˵����ɶ ��ʣ1���и�Ĵ� �����Ƴ�����Ĵ�

    // ����ѡ�� ��С��

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
