#include<bits/stdc++.h>
#include<windows.h>
using namespace std;
signed main(){
	
	// system("Fragrant numbers.exe < data.txt > ans1.txt");
	{
		system("data.exe > data.txt");
		system("Fragrantnumbers.exe < data.txt  > ans1.txt");
		system("Fragrantnumbers1.exe < data.txt > ans2.txt");
		if(system("fc ans1.txt ans2.txt")){
			cout << "error" << endl;
			
		}
	}
}