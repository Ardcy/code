#include<bits/stdc++.h>
using namespace std;
int a[30],b[30];
char p[30];
signed main() {
	string s;
	cin>>s;

	int l =s.length();
	int y = 0;
	for(int i=l-1; i>=0; i--) {
		p[i]=(y+(s[i]-'0')*2)%10+'0';
		y=(y+(s[i]-'0')*2)/10;
		a[s[i]-'0']++;
		b[p[i]-'0']++;
	}
	if(y!=0) {
		cout<<"No"<<endl;
		int cnt  = 0;
		cout<<y;
		while(p[cnt]>='0'&&p[cnt]<='9') {
			cout<<p[cnt++];
		}
		cout<<endl;
		return 0;
	} else {
		int fl = 1;
		for(int i=0; i<10; i++)if(a[i]!=b[i])fl=0;
		if(fl) {
			cout<<"Yes\n";
			int cnt  = 0;
			while(p[cnt]>='0'&&p[cnt]<='9') {
				cout<<p[cnt++];
			}
			cout<<endl;
		} else {
			cout<<"No"<<endl;
			int cnt  = 0;
			while(p[cnt]>='0'&&p[cnt]<='9') {
				cout<<p[cnt++];
			}
			cout<<endl;
		}

	}


}
