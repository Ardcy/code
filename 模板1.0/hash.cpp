#include<bits/stdc++.h>
#define debug(x) cerr<<#x<<"="<<x<<endl
using namespace std;
unsigned int hasha(char *url,int mod){
	
	unsigned int n = 0;
	char *b = (char *)&n;
	for(int i=0;url[i];++i)b[i%4]^=url[i];
	return n%mod;
}
int hashb(char *url,int mod){
	unsigned int h=0,g;
	while(*url){
		h=(h<<4)+*url++;
		g = h& 0xF0000000;
		if(g)h^=g>>24;
		h&=~g;
	}
	return h % mod;
}
int main(){
	char h[10] = "abas";
	cout<<hashb(h,10000);
}
