//#include<bits/stdc++.h>
//using namespace std;
//map<string,int>P;
//signed  main(){
//	string s;
//	cin>>s;
//	int l=s.length();
//	for(int i=0;i<l-1;i++){
//		P[s.substr(i,2)]++;
//	}
//	for(int i=0;i<l-2;i++){
//		P[s.substr(i,3)]++;
//	}
//	for(int i=0;i<l-3;i++)P[s.substr(i,4)]++;
//	if(P["AB"]>=1&&P["BA"]>=1){
//		if(P["AB"]==1&&P["BA"]==1&&(P["ABA"]==1||P["BAB"]==1)){
//			cout<<"NO"<<endl;
//		}else if((P["AB"]+P["BA"]==3)&&(P["ABA"]==1&&P["BAB"]==1)&&(P["ABAB"]==1||P["BABA"]==1)){
//			cout<<"NO"<<endl;
//		}
//		else cout<<"YES"<<endl;
//	} else
//	cout<<"NO"<<endl;	
//	return 0;
//}
//

#include<bits/stdc++.h>
using namespace std;

signed main(){
	string s;
	cin>>s;
	if(s.find("AB")==string::npos||s.find("BA")==string::npos){
		cout<<"NO"<<endl;return 0;
	}
	int pt = s.find("AB");
	int pr = s.find("BA");
	if(s.find("BA",pt+2)==string::npos&&s.find("AB",pr+2)==string::npos){
		cout<<"NO"<<endl;
	}else cout<<"YES"<<endl; 
	
	return 0;	
}
