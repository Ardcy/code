#include<bits/stdc++.h>
using namespace std;
#define int long long
double C(int a,int b){
	
	double ans=1;
	for(int i=1;i<=b;i++){
		if(i<=a)ans*=((double)i/(i*2.0));
		else {
			
			ans*=((double)i/((b-i+1)*2.0));
		}
	}
	return ans;
}
signed main(){
	
	
	string s,h;
	cin>>s>>h;
	int a=0,b=0;
	for(int i=0;i<s.length();i++){
		if(s[i]=='+')a++;
		else a--;
	}
	int cnt=0;
	for(int i=0;i<s.length();i++){
		if(h[i]=='+')b++;
		else if(h[i]=='-')b--;
		else cnt++;
	}
	
	for(int i=0;i<=cnt;i++){
		if(abs(cnt-2*i)==abs(b-a))
		{
			//cout<<cnt<<abs(a-b)<<endl;
			printf("%.14f\n",C(cnt-i,cnt));	
			return 0;
		}
	}
	printf("%.14f\n",0);	
	
	return 0;
}
