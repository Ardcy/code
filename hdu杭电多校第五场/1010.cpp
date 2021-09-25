#include<bits/stdc++.h>
using namespace std;
#define int long long
#define fi first
#define se second
#define inf INT_MAX
#define mp make_pair
#define pb push_back
const int mod = 998244353;
int qp(int a,int b){int ans=1;while(b){if(b&1)ans*=a,ans%=mod;a*=a,a%=mod;b>>=1;}return ans;};

const int MAXN = 1000;
int  t[MAXN], A[MAXN];
char OldData[MAXN], NewData[MAXN];  // 转换前、后的数据
int olds, news;                     // 转换前、后的进制
char s[MAXN];
char A1[MAXN],B1[MAXN],C1[MAXN];
void trans()
{
    int i, len, k;
    len = strlen(OldData);
    for(i=len; i>=0; --i)
        t[len-1-i] = OldData[i] - (OldData[i]<58 ? 48 : OldData[i]<97 ? 55 : 61);
    for(k=0; len;)
    {
        for(i=len; i>=1; --i)
        {
            t[i-1] += t[i]%news*olds;
            t[i] /= news;
        }
        A[k++] = t[0] % news;
        t[0] /= news;
        while(len>0 && !t[len-1]) --len;
    }
    NewData[k] = NULL;
    for(i=0; i<k; ++i)
        NewData[k-1-i] = A[i] + (A[i]<10 ? 48 : A[i]<36 ? 55 : 61);
}

signed main(){
//	char str[]="1234";
	
//	strcpy(str,"cc ");
//	cout<<str<<endl;
	
//	cin>>OldData;
	olds = 16, news = 10;
	trans();
	
//	cout<<NewData<<endl;

	while(~scanf("%s",s)){
		//cout<<s<<endl;
		int in1,in2;
		int p =strlen(s);
		//cout<<"长度"<<p<<endl;
		strcpy(A1,"");
		strcpy(B1,"");
		strcpy(C1,"");
	
		char q;
		for(int i=0;i<p;i++){
			
	
			if(s[i]=='+'||s[i]=='-'||s[i]=='*'||s[i]=='/')
				in1 = i,q=s[i];
			else if(s[i]=='=')in2 = i;
		}
		for(int i=0;i<in1;i++)A1[i]=s[i];
		A1[in1]='\0';
		for(int i=0+in1+1;i<in2;i++)B1[i-in1-1]=s[i];
		B1[in2-in1-1]='\0';
		for(int i=in2+1;i<p;i++)C1[i-in2-1]=s[i];
	    C1[p-in2-1]='\0';
//		cout<<A1<<endl;
//		cout<<B1<<endl;
//		cout<<C1<<endl;
	
		int f = 0;
		int a1,b1,c1;
		for(int k=2;k<=16;k++){
			olds = k,news = 10;
			strcpy(OldData,A1);
			trans();
			a1 = atoi(NewData);
			
			strcpy(OldData,B1);
			trans();
			b1 = atoi(NewData);
			
			strcpy(OldData,C1);
			trans();
			c1 = atoi(NewData);
			
			if(q=='+'){
				if(a1+b1==c1){
					f=k;
				}
			}
			if(q=='-'){
				if(a1-b1==c1){
					f=k;
				}
			}
			if(q=='*'){
				if(a1*b1==c1){
					f=k;
				}
			}
			if(q=='/'){
				if(a1/b1==c1&&a1%b1==0){
					f=k;
				}
			}
		}
		if(f)cout<<f<<endl;
		else cout<<-1<<endl;
		strcpy(s,"");
	}
	return 0;
}


