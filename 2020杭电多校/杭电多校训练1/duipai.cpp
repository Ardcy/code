#include<bits/stdc++.h>
#include<windows.h>
using namespace std;
signed main(){
	while(1){
		system("data.exe > in.txt");
		system("Leading Robots.exe < in.txt > out1.txt");
		system("Leading Robots.exe < in.txt > out2.txt");
		if(system("fc out1.txt out2.txt")){
			cout << " error " << endl;
			break;
		}
	}
}