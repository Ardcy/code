#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e5+5;
int arr[N+5];
const int mod = 998244353;
int ax,ay,bx,by,cx,cy,dx,dy;
int n,m,k;
 
template<typename T>
T RandT(T _min, T _max)
{
	T temp;
	if (_min > _max)
	{
		temp = _max;
		_max = _min;
		_min = temp;
	}
	return rand() / (double)RAND_MAX *(_max - _min) + _min;
}
 




struct node{
	int x,y;
}e[3000];


int cal(int a1,int b1){
	int ans = 0;
	for(int i=1;i<=m;i++){
		
		int ans1 = max(1+min(a1+k-1,e[i].y)-max(a1,e[i].x),0ll);
		int ans2 = max(1+min(b1+k-1,e[i].y)-max(b1,e[i].x),0ll);
		
		//cout<< ans1 <<" "<<ans2 <<endl;
		ans += max(ans1,ans2);
	} 
	return ans;
	//cout<<" a1 = "<<a1 <<" a2 = "<<" "<<b1<<" ans = "<< ans <<endl;return ans;
}



signed main(){
	srand((unsigned)time(NULL));
	
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>e[i].x>>e[i].y;	
	}
	int  l = 1, r = n-k+1;
	
	int lx = 1,ly = r,rx = 1,ry = r;
    int cnt = 0;
    
    int ans = cal(1ll,1ll);
    int x = 1, y = 1;
    //cout<<cal(1ll,6ll)<<endl;
    while(cnt<=1000)
    {
		cnt++;
		int lx = (RandT<int>(1,r));
		int ly = (RandT<int>(1,r));
		lx%=(r+1);
		ly%=(r+1);
		//cout << lx << " " << ly << endl;
		
		for(int i=max(1ll,lx-10);i<=min(r,lx+10);i++){
			for(int j=max(1ll,ly-10);j<=min(r,ly+10);j++)ans = max(ans,cal(i,j));
		}
		if(ans < cal(lx,ly)){
			ans = cal(lx,ly);
			x += lx;
			x%=(r+1);
			y += ly;
			y%=(r+1);
		
		}
		ans = max(ans,cal(x,y));	
		
    }
    printf("%lld\n",ans);
    return 0;
}
