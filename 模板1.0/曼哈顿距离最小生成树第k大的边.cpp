//POJ3241; Object Clustering; Manhattan Distance MST
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#define N 100000
#define INFI 123456789
 
struct point
{
    int x, y, n;
    bool operator < (const point &p) const
    { return x == p.x ? y < p.y : x < p.x; }
}p[N + 1];
struct inedge
{
    int a, b, w;
    bool operator < (const inedge &x) const
    { return w < x.w; }
}e[N << 3 | 1];
struct BITnode
{
    int w, p;
}arr[N + 1];
int n, k, tot = 0, f[N + 1], a[N + 1], *l[N + 1], ans;
 
template <typename T>
inline T abs(T x)
{ return x < (T)0 ? -x : x; }
 
int find(int x)
{ return x == f[x] ? x : f[x] = find(f[x]); }
 
inline bool cmp(int *a, int *b)
{ return *a < *b; }
 
inline int query(int x)
{
    int r = INFI, p = -1;
    for (; x <= n; x += x & -x)
        if (arr[x].w < r) r = arr[x].w, p = arr[x].p;
    return p;
}
 
inline void modify(int x, int w, int p)
{
    for (; x > 0; x -= x & -x)
        if (arr[x].w > w) arr[x].w = w, arr[x].p = p;
}
 
inline void addedge(int a, int b, int w)
{
    ++tot;
    e[tot].a = a, e[tot].b = b, e[tot].w = w;
//  printf("%d %d %d\n", a, b, w);
}
 
inline int dist(point &a, point &b)
{ return abs(a.x - b.x) + abs(a.y - b.y); }
 
int main()
{
    //Initialize
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; ++i)
    {
        scanf("%d%d", &p[i].x, &p[i].y);
        p[i].n = i;
    }
    //Solve
    for (int dir = 1; dir <= 4; ++dir)
    {
        //Coordinate transform - reflect by y=x and reflect by x=0
        if (dir == 2 || dir == 4)
            for (int i = 1; i <= n; ++i) p[i].x ^= p[i].y ^= p[i].x ^= p[i].y;
        else if (dir == 3)
            for (int i = 1; i <= n; ++i) p[i].x = -p[i].x;
        //Sort points according to x-coordinate
        std::sort(p + 1, p + n + 1);
        //Discretize
        for (int i = 1; i <= n; ++i) a[i] = p[i].y - p[i].x, l[i] = &a[i];
        std::sort(l + 1, l + n + 1, cmp);
        /*
        int cnt = 1;
        for (int i = 2; i <= n; ++i)
            if (*l[i] != *l[i - 1]) *l[i - 1] = cnt++;
            else *l[i - 1] = cnt;
        *l[n] = cnt;
        */
        for (int i = 1; i <= n; ++i) *l[i] = i;
        //Initialize BIT
        for (int i = 1; i <= n; ++i) arr[i].w = INFI, arr[i].p = -1;
        //Find points and add edges
        for (int i = n; i > 0; --i)
        {
            int pos = query(a[i]);
            if (pos != -1)
                addedge(p[i].n, p[pos].n, dist(p[i], p[pos]));
            modify(a[i], p[i].x + p[i].y, i);
        }
    }
    //Kruskal
    std::sort(e + 1, e + tot + 1);
    for (int i = 1; i <= n; ++i) f[i] = i;
    for (int i = 1, ec = n; ec > k && i <= tot; ++i)
        if (find(e[i].a) != find(e[i].b))
        {
            f[find(e[i].a)] = find(e[i].b);
            if (--ec == k) ans = e[i].w;
        }
    printf("%d\n", ans);
    return 0;
}
