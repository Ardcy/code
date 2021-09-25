#include<bits/stdc++.h>
using namespace std;
int c[105000];
int d[105000];
int main(){
	int T;
	cin>>T;
	while(T--){
		int a;
		cin>>a;
		string b;
		cin>>b;

		int cnt1 = 1;
		int cnt2 = a;
		for(int i=0;i<a-1;i++){
			if(b[i]=='>')cout<<(cnt2--)<<" ";
			else  cout<<(cnt1++)<<" ";
		} 
		cout<<cnt1<<endl;
		int start = 0;
		int last = 0;
		for(int i=0;i<a-1;i++){
			if(b[i]=='<'){
				start=i;
				break;
			}
		}
		for(int i=a-2;i>=0;i--){
			if(b[i]=='<'){
				last = i;
				break;
			}
		}
		
		int cnt3 = last-start+1;
		for(int i = 1;i<a-2;i++){
			if(i>=start&&b[i-1]=='>'&&b[i]=='>'&&b[i+1]=='<'){
				//b[i]='<';
				d[i]=1;	
			}
			d[i]=0;
		}
		cnt1 = 1;
		cnt2 = a;
		for(int i=0;i<a-1;i++){
			if(b[i]=='>')c[i]=(cnt2--);
			else  c[i]=(cnt1++);
		} 
		c[a-1]=cnt1;
		for(int i=0;i<a;i++){
			if(!d[i])cout<<c[i]<<" ";
			else{
				 cout<<c[i+1]<<" "<<c[i]<<" ";
				 i++;
			}
		}
		cout<<endl;
	}
}
