#include <cstdio>
#include <cstring>
int f[33][33][33][2], a[33];
void init() {
    memset(f, -1, sizeof(f));
}
int dfs(int pos, int num0, int num1, bool all0, bool limit) {
    if (pos < 0)    // 遍历完所有数位
        return num0 >= num1 ? 1 : 0;
    if (num0 + pos + 1 < num1)  // 0的个数用于达不到1的个数
        return 0;
    if (!limit && f[pos][num0][num1][all0] != -1) return f[pos][num0][num1][all0];
    int up = limit ? a[pos] : 1;
    int tmp = 0;
    for (int i = 0; i <= up; i ++) {
        tmp += dfs(pos-1, num0 + (!all0 && i==0), num1 + (i==1), all0 && i==0, limit && i==up);
    }
    if (!limit) f[pos][num0][num1][all0] = tmp;
    return tmp;
}
int get_num(int x) {
    int pos = 0;
    while (x) {
        a[pos++] = x % 2;
        x /= 2;
    }
    return dfs(pos-1, 0, 0, true, true);
}
int main() {
    init();
    int x, y;
    while (~scanf("%d%d", &x, &y)) {
        printf("%d\n", get_num(y) - get_num(x-1));
    }
    return 0;
}