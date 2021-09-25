#include<bits/stdc++.h>
using namespace std;
signed main(){

	//system("data.exe > in.txt");

	while(1){
		system("data.exe > in.txt");
		system("D.exe < in.txt > out1.txt");
		system("D1.exe < in.txt > out2.txt");
		if(system("fc out1.txt out2.txt")){
			cout << " error "<<endl;
			break;
		}
	}
}