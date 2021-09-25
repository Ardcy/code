//曼哈顿距离最小生成树 


//离散化：
    scanf("%d", &N);
    for (int i=1; i<=N; ++i)
    {
        scanf("%d%d", &P[i].x, &P[i].y);
        P[i].id = i;
        P[i].d = P[i].y - P[i].x;
        P[i].s = P[i].y + P[i].x;
    }
    //对x,y离散化
    int totxy = 0;
    for (int i=1; i<=N; ++i)
    {
        xy[totxy++] = P[i].x;
        xy[totxy++] = P[i].y;
    }
    sort(xy, xy+totxy);
    for (int i=1; i<=N; ++i)
    {
        P[i].idx = lower_bound(xy, xy+totxy, P[i].x) - xy + 1;
        P[i].idy = lower_bound(xy, xy+totxy, P[i].y) - xy + 1;
    }
//树状数组：
struct BIT
{
    pii a[maxN * 2];
    int N;
    void Init(int _N)
    {
        N = _N;
        for (int i=0; i<=N; ++i) a[i] = pii(oo, 0);
    }
    pii ask(int x)
    {
        return x == 0 ? pii(oo, 0) : min(a[x], ask(x - (x & (-x))));
    }
    void update(int x, const pii &v)
    {
        if (x > N) return ;
        a[x] = min(a[x], v);
        update(x + (x & (-x)), v);
    }
     
    pii ask_front(int x) {return ask(x);}
    pii ask_back(int x) {return ask(N - x + 1);}
    void update_front(int x, const pii &v) {update(x, v);}
    void update_back(int x, const pii &v) {update(N - x + 1, v);}
} tree;
//构图：
bool cmp1(const Tpoint &A, const Tpoint &B) 
{
    //return A.x < B.x || (A.x == B.x && A.y < B.y);
    return (A.y - A.x > B.y - B.x || A.y - A.x == B.y - B.x && A.x > B.x);
}
bool cmp2(const Tpoint &A, const Tpoint &B) 
{
    //return A.x < B.x || (A.x == B.x && A.y > B.y);
    return (A.y + A.x < B.y + B.x || A.y + A.x == B.y + B.x && A.x > B.x);
}
bool cmp3(const Tpoint &A, const Tpoint &B) 
{
    //return A.y < B.y || (A.y == B.y && A.x < B.x);
    return A.y - A.x < B.y - B.x || A.y - A.x == B.y - B.x && A.y > B.y;
}
bool cmp4(const Tpoint &A, const Tpoint &B) 
{
    //return A.y < B.y || (A.y == B.y && A.x > B.x);
    return A.s > B.s || A.s == B.s && A.y < B.y;;
}
 
bool cmpE(const E_arr &A, const E_arr &B) {return A.v < B.v;} 
 
void Make_Graph()
{
    #define Connect(i,j) E[++tot_E].Init(P[i].id,P[j].id,getdis(i,j))
     
    int LL, RR;
     
    tree.Init(2 * N);
    sort(P+1, P+N+1, cmp1);
    for (int i=1; i<=N; ++i)
    {
        pii tmp = tree.ask_back(P[i].idx);
        if (tmp.first < oo) Connect(i, tmp.second);
        tree.update_back(P[i].idx, pii(P[i].x + P[i].y, i));
    }
     
    sort(P+1, P+N+1, cmp2);
    tree.Init(2 * N);
    for (int i=1; i<=N; ++i)
    {
        pii tmp = tree.ask_back(P[i].idx);
        if (tmp.first < oo) Connect(i, tmp.second);
        tree.update_back(P[i].idx, pii(P[i].x - P[i].y, i));
    }
     
    sort(P+1, P+N+1, cmp3);
    tree.Init(2 * N);
    for (int i=1; i<=N; ++i)
    {
        pii tmp = tree.ask_back(P[i].idy);
        if (tmp.first < oo) Connect(i, tmp.second);
        tree.update_back(P[i].idy, pii(P[i].x + P[i].y, i));
    }
     
    sort(P+1, P+N+1, cmp4);
    tree.Init(2 * N);
    for (int i=1; i<=N; ++i)
    {
        pii tmp = tree.ask_front(P[i].idy);
        if (tmp.first < oo) Connect(i, tmp.second);
        tree.update_front(P[i].idy, pii(P[i].x - P[i].y, i));
    }
}
