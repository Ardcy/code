#include<iostream>
#include<cstdio>
#include<cmath>
#define fo(i,b,c) for(int i=(b);i<=(c);i++)
using namespace std;
const double pi = acos(-1.0);
int rev[2005000];
const int MAXN = 2005000;
struct complex {
	double x,y;
	complex (double xx=0,double yy=0) {
		x=xx,y=yy;
	}
	complex operator + (complex &t)const{
		return complex(x+t.x,y+t.y);
	} 
	complex operator - (complex &t)const{
		return complex(x-t.x,y-t.y);
	} 
	complex operator * (complex &t)const{
		return complex(x*t.x-y*t.y,x*t.y+y*t.x);
	} 
	
} a[MAXN],b[MAXN];
void fft(complex *a,int n,int inv) {
	int bit=0;
	while ((1<<bit)<n)bit++;
	fo(i,0,n-1) {
		rev[i]=(rev[i>>1]>>1)|((i&1)<<(bit-1));
		if (i<rev[i])swap(a[i],a[rev[i]]);//��������if�ύ�����Σ�����û������
	}
	for (int mid=1; mid<n; mid*=2) { //mid��׼���ϲ����еĳ��ȵĶ���֮һ
		complex temp(cos(pi/mid),inv*sin(pi/mid));//��λ����pi��ϵ��2�Ѿ�Լ����
		for (int i=0; i<n; i+=mid*2) { //mid*2��׼���ϲ����еĳ��ȣ�i�Ǻϲ�������һλ
			complex omega(1,0);
			for (int j=0; j<mid; j++,omega=omega*temp) { //ֻɨ��벿�֣��õ��Ұ벿�ֵĴ�
				complex x=a[i+j],y=omega*a[i+j+mid];
				a[i+j]=x+y,a[i+j+mid]=x-y;//������Ǻ����任ʲô��
			}
		}
	}
}
int c[MAXN];
signed main() {
	int n,m;
	cin>>n>>m;
	int u;
	for(int i=0; i<=n; i++) {
		cin>>u;
		a[i].x=u;
	}
	for(int i=0; i<=m; i++) {
		cin>>u;
		b[i].x=u;
	}
	int limit = 1;
	while(limit<=n+1+m+1)limit<<=1;
	fft(a,limit,1),fft(b,limit,1);//1ϵ��ת��ֵ
	fo(i,0,limit)a[i]=a[i]*b[i];
	fft(a,limit,-1);//-1��ֵתϵ��
	fo(i,0,m+n)cout<<(int)(a[i].x/limit+0.5)<<" ";//ע�⾫��
	cout<<endl;
}




