#include <iostream>
#include <vector>
#include <map>
#include <cstring>
#include <queue>
#include <sstream>
#define int long long
using namespace std;
#define int long long
int a[2000];
signed main()
{
	a[1]=1;
	a[0]=0;
	for(int i=2;i<100;i++){
		a[i]=a[i-1]+a[i-2];
		if(a[i]>1e9){
			cout<<i<<endl;
			break;	
		}
	}
	
	
	return 0;
}
