#include<bits/stdc++.h>
#include<windows.h>
using namespace std;
signed main(){
	while(1){
		system("data.exe > data.txt");
		system("p1.exe < data.txt > p1.txt");
		system("p2.exe < data.txt > p2.txt");
		if(system("fc p1.txt p2.txt")){
			cout<<"error"<<endl;
			break;
		}
	}
	
}
