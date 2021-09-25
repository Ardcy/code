#include<bits/stdc++.h>
#include<windows.h>
using namespace std;
signed main(){
	while(1){
		system("data.exe > data.txt");

		system("C.exe < data.txt > E1.txt");
		system("st.exe < data.txt > E_r.txt");
		if(system("fc E1.txt E_r.txt")){
			cout<<"error"<<endl;
			break;
		}
	}
	
}

// #include<bits/stdc++.h>
// #include<window.h>
// using namespace std;
// signed main(){

// 	system("data.exe > in.txt");


// 	// while(1){
// 	// 	system("data.exe > in.txt");
// 	// 	system("C.exe < in.txt > out.txt");
// 	// 	system("st.exe < in.txt > out1.txt");
// 	// 	if(system("fc out1.txt out.txt")){
// 	// 		cout <<"error" << endl;
// 	// 		break;
// 	// 	}
// 	// }
// }