#include<bits/stdc++.h>
#define debug(x) cerr<<#x<<"="<<x<<endl
#define int long long
using namespace std;
int fail[3];
int kmp(char* str,char* pat){
	int i,j,k;
	memset(fail,-1,sizeof(fail));
	for(i=1;pat[i];++i){
		for(k=fail[i-1];k>=0&&pat[i]!=pat[k+1];k=fail[k]);
		if(pat[k+1]==pat[i])fail[i] = k+1;
	}
	i = j = 0;
	while(str[i]&&pat[j]){
		if(pat[j]==str[i])++i,++j;
		else if(j==0)++i;
		else j = fail[j-1]+1;
		
	}
	if(pat[j])return -1;
	else return i-j;
}
signed main(){
	char h[20]="abcdefgabc";
	char d[5]="gabc";
	cout<<kmp(h,d)<<endl;
	cout<<strstr(h,d)<<endl;
}
