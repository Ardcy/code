#include<bits/stdc++.h>
using namespace std;
#define int long long
#define fi first
#define se second
#define inf INT_MAX
#define mp make_pair
char s[205000];
char t1[205000];
char a[] = "ora";
char b[]= "muda";
char c[]= "zawaluduo";
struct node{
	int x,y;
}e[205000];
bool cmp(node a,node b){
	if(a.x==b.x)return a.y<b.y;
	return a.x<b.x;
}
signed main(){
	int t;
	cin>>t;
	int cntt = 0;
	while(t--){
		cntt++;
		int n,h;
		cin>>n>>h;
		int a1=h,a2=h;
		cin>>s;
		cin>>t1;
		//cout<<s<<endl;
		//cout<<t1<<endl;
		int y = 0;
		int cnt = 0;
		while(strstr(s+y,a)!=NULL){
			y=strstr(s+y,a)-s+2;
			e[++cnt]={y,1};
		}
		y=0;
		while(strstr(t1+y,b)!=NULL){
			y=strstr(t1+y,b)-t1+3;
			e[++cnt]={y,2};
		}
		int l1 = 1e9,l2 = 1e9;
		if(strstr(s,c)!=NULL){
			l1=min(l1,(int)(strstr(s,c)-s+8));
		}
		if(strstr(t1,c)!=NULL){
			l2=min(l2,(int)(strstr(t1,c)-t1+8));
		}
		//cout<<"l1="<<l1<<" l2="<<l2<<endl;
		sort(e+1,e+cnt+1,cmp);
		
		//cout<<cnt<<endl;
		for(int i=1;i<=cnt;i++){
		//	cout<<e[i].x<<" "<<e[i].y<<endl;
		}
		e[cnt+1]={10000000,6};
		for(int i=1;i<=cnt;i++){
			if(e[i].x>=l2){
				cout<<"Hinnjaku"<<endl;
				a1=0;
				break;
			}
			if(e[i].x>=l1){
				cout<<"Wryyyyy"<<endl;
				a2=0;
				break;
			}
			if(e[i].x!=e[i+1].x){
				if(e[i].y==1)a2--;
				if(e[i].y==2)a1--;
				
			}else{
				a1--;a2--;
				i+=1;
			}
			if(a2==0&&a1>0){
				cout<<"Wryyyyy"<<endl;
				break;
			}
			if(a1==0&&a2>0){
				cout<<"Hinnjaku"<<endl;
				break;
			}
			if(a1==0&&a2==0){
				cout<<"Kono Dio da"<<endl;
				break;
			}	
		}
		if(a1!=0&&a2!=0){
			if(a2>a1){
				cout<<"Wryyyyy"<<endl;
		
			}
			if(a1>a2){
				cout<<"Hinnjaku"<<endl;
			
			}
			if(a1==a2){
				cout<<"Kono Dio da"<<endl;
			}
		}
		int ui,ans=0;
//		if(cntt>=2){
//			for(int i=1;i<=(int)1e9;i++){
//				ans=ui*i;
//				ans=ans%(ans-1);
//				ans=ans*ans-ans;
//			}
//		}
	}
	return 0;
}


