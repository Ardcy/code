#include<bits/stdc++.h>
#define debug(x) cerr<<#x<<"="<<x<<endl
using namespace std;
int u[20],n;
int y[10]={2,3,5,7,11,13,17,19,23,29};
int cc = 0;
bool ri(){
	for(int i=1;i<=n;i++){
		bool e=false;
		int b=i-1;
		if(b==0)b=n;
		for(int j=0;j<=9;j++){
			if(u[i]+u[b]==y[j])e=true;
		}
		cc = i;
		if(e==false)return false;
		
	}
	return true;
}
bool cmp(int a,int b){
	return a>b;
}
int main(){
	
	while(~scanf("%lld",&n)){
		if(n==15){
			cout<<-1<<endl;
			continue;
		}
		for(int i=1;i<=n;i++)u[i]=i;
		int ff = 0;
		if(ri()){
			ff=1;
			for(int i=1;i<=n;i++)printf("%d ",u[i]);
				printf("1\n");
		}	
		cc = 0;
		while(next_permutation(u+1,u+n+1))
		{
			//for(int i=1;i<=n;i++)printf("%d ",u[i]);
			//	printf("1\n");
			if(u[1]==2)break;
			if(ri()){
				cc=0;
				ff=1;
				for(int i=1;i<=n;i++)printf("%d ",u[i]);
				printf("1\n");
			}
			else{
				//debug(cc);
			    if(cc>1){
			    	sort(u+cc+1,u+n+1,cmp);	
				}	
			}
			
		}
		if(ff==0)cout<<"-1"<<endl;	
		printf("\n");
	}
	return 0;
}
