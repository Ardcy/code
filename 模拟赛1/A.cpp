#include<bits/stdc++.h>
using namespace std;

struct   TPoint   
{   
         double x,y;   
}; 
TPoint a[6005],d; 
double r;

double   distance(TPoint   p1,   TPoint   p2)   
{   
          return (sqrt((p1.x-p2.x)*(p1.x -p2.x)+(p1.y-p2.y)*(p1.y-p2.y)));       
}
double multiply(TPoint   p1,   TPoint   p2,   TPoint   p0)   
{   
          return   ((p1.x-p0.x)*(p2.y-p0.y)-(p2.x-p0.x)*(p1.y-p0.y));           
}   
void MiniDiscWith2Point(TPoint   p,TPoint   q,int   n)
{
d.x=(p.x+q.x)/2.0;
d.y=(p.y+q.y)/2.0;
r=distance(p,q)/2;
int k;
double c1,c2,t1,t2,t3;
for(k=1;k<=n;k++)
{
if(distance(d,a[k])<=r)continue;
if(multiply(p,q,a[k])!=0.0) ////不平行
{
   c1=(p.x*p.x+p.y*p.y-q.x*q.x-q.y*q.y)/2.0;
   c2=(p.x*p.x+p.y*p.y-a[k].x*a[k].x-a[k].y*a[k].y)/2.0;

   d.x=(c1*(p.y-a[k].y)-c2*(p.y-q.y))/((p.x-q.x)*(p.y-a[k].y)-(p.x-a[k].x)*(p.y-q.y));
   d.y=(c1*(p.x-a[k].x)-c2*(p.x-q.x))/((p.y-q.y)*(p.x-a[k].x)-(p.y-a[k].y)*(p.x-q.x));
   r=distance(d,a[k]);
}
else        //平行
{
    t1=distance(p,q);
    t2=distance(q,a[k]);
    t3=distance(p,a[k]);
    if(t1>=t2&&t1>=t3)
    {d.x=(p.x+q.x)/2.0;d.y=(p.y+q.y)/2.0;r=distance(p,q)/2.0;}
    else if(t2>=t1&&t2>=t3)
    {d.x=(a[k].x+q.x)/2.0;d.y=(a[k].y+q.y)/2.0;r=distance(a[k],q)/2.0;}
    else 
    {d.x=(a[k].x+p.x)/2.0;d.y=(a[k].y+p.y)/2.0;r=distance(a[k],p)/2.0;}
}
}

}
void MiniDiscWithPoint(TPoint   pi,int   n)
{
d.x=(pi.x+a[1].x)/2.0;
d.y=(pi.y+a[1].y)/2.0;
r=distance(pi,a[1])/2.0;
int j;
for(j=2;j<=n;j++)
{
if(distance(d,a[j])<=r)continue;
else
{
   MiniDiscWith2Point(pi,a[j],j-1);
}
}

}


double P[3][6000];
int main()
{


	int i,n;
	cin >> n;
	for(int i=1;i<=n;i++){
		cin >> P[0][i] >> P[1][i] >> P[2][i];
	}
	double minr = 1000000000000.0;
	for(int ui = 0;ui < 3;ui++)
	{
		for(i=1;i<=n;i++)
		{
			a[i].x = P[ui][i];
			a[i].y = P[(ui+1)%3][i];
		   
		}
		
		r=distance(a[1],a[2])/2.0;
		d.x=(a[1].x+a[2].x)/2.0;
		d.y=(a[1].y+a[2].y)/2.0;
		for(i=3;i<=n;i++)
		{
		   if(distance(d,a[i])<=r)continue;
		   else
		    MiniDiscWithPoint(a[i],i-1);
		}
		minr = min(minr,r);
		
	}
	//cout << minr << endl;
	printf("%.10f\n",minr*2);
	return 0;
}