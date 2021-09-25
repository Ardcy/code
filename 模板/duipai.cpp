#include<bits/stdc++.h>
using namespace std;
signed main(){
	while(1){
		system("data.exe  > in.txt");
		system("ceshi.exe < in.txt > out.txt");
		system("baoli.exe < in.txt > out2.txt");
		if(system("fc out.txt out2.txt")){
			cout <<"error" << endl;
			break;
		}
	}
}