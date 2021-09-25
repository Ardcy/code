#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>

using namespace std;

const double eps = 1e-9;
int ax,ay,bx,by,cx,cy,dx,dy;
int p,d,q;

double dis(double x1,double y1,double x2,double y2)
{
    return sqrt((x1 - x2) * (x1 - x2) + (y2 - y1) * (y2 - y1));
}
                
double cal(double x1,double y1,double x2,double y2)
{
    return dis(ax,ay,x1,y1) / p + dis(x1,y1,x2,y2) / d + dis(x2,y2,dx,dy) / q;
}

double solve(double x,double y)
{
    double lx = cx,ly = cy,rx = dx,ry = dy;
    while(fabs(rx - lx) > eps || fabs(ry - ly) > eps)
    {
        double x1 = lx + (rx - lx) / 3,x2 = lx + (rx - lx) / 3 * 2;
        double y1 = ly + (ry - ly) / 3,y2 = ly + (ry - ly) / 3 * 2;
        if(cal(x,y,x1,y1) > cal(x,y,x2,y2))
        {
            lx = x1;
            ly = y1;
        }
        else
        {
            rx = x2;
            ry = y2;
        }
    }
    return cal(x,y,lx,ly);
}

int main()
{
    scanf("%d%d%d%d%d%d%d%d",&ax,&ay,&bx,&by,&cx,&cy,&dx,&dy);
    scanf("%d%d%d",&p,&q,&d);
    
    double lx = ax,ly = ay,rx = bx,ry = by;
    
    while(fabs(rx - lx) > eps || fabs(ry - ly) > eps)
    {
        double x1 = lx + (rx - lx) / 3,x2 = lx + (rx - lx) / 3 * 2;
        double y1 = ly + (ry - ly) / 3,y2 = ly + (ry - ly) / 3 * 2;
        if(solve(x1,y1) > solve(x2,y2))
        {
            lx = x1;
            ly = y1;
        }
        else
        {
            rx = x2;
            ry = y2;
        }
    }
    printf("%.2f\n",solve(lx,ly));
    return 0;
}


