#include<bits/stdc++.h>
#include<windows.h>
using namespace std;
signed main(){
	while(1){
		system("data.exe > data.txt");

		system("E2.exe < data.txt > E1.txt");
		system("st.exe < data.txt > E_r.txt");
		if(system("fc E1.txt E_r.txt")){
			cout<<"error"<<endl;
			break;
		}
	}
	
}
