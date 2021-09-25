#include<bits/stdc++.h>
using namespace std;
#define N 200050
int a[N];
int b[N][2];
int main(){
    int k,n;
    cin>>n>>k;
    getchar();
    int f = 0;
    for(int i = 1;i<=n;i++){
    	
        a[i] = getchar() - '0';
        if(!a[1]&&i==1){
			a[1]=1;f = 1;
		}
        if(f&&i>1)a[i]=1-a[i];
    }
    int cnt = 0;
    for(int i = 1;i<=n;i++){
        if(a[i])
        {
		 	b[++cnt][0] = i;
            while(a[i])i++;
			b[cnt][1] = i-1; 
        }
    }
    int ans = 0;
    if(k>=cnt){
	cout<<n<<endl;return 0;}
    if(k<cnt){
    	for(int i = 1;i<=cnt-k;i++){
    		ans=max(ans,b[i+k][1]+1-b[i][0]);
		}
		for(int i = 1;i+k+1<=cnt;i++){
			ans = max(b[i+k+1][0]-b[i][1]-1,ans);
		}
		if(b[cnt][1]!=n){	
			ans = max(ans,n-b[cnt-k][1]);
		} 
	}
	cout<<ans<<endl;
}
