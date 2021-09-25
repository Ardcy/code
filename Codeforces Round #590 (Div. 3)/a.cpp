#include <iostream> 
#include <cstdio> 
#include <fstream> 
#include <algorithm> 
#include <cmath> 
#include <deque> 
#include <vector> 
#include <queue> 
#include <string> 
#include <cstring> 
#include <map> 
#include <stack> 
#include <set>
using namespace std;
signed main(){
	int t;
	cin>>t;
	int n;
	while(t--){
		cin>>n;
		int sum=0;
		int d;
		for(int i=1;i<=n;i++){
			cin>>d;
			sum+=d;
		}
		
		cout<<(sum/n+(sum%n>0))<<endl;
	}
}
