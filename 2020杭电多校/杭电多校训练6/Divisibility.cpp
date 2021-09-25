#include<bits/stdc++.h>
using namespace std;
#define int long long 
void check(int x,int y){

	int num = 100;
	int cnt = 0;
	int base = 1;int ans = 0;
		int ans1 = 0;
	for(int i=1;i<=100;i++)
	{
		ans = 0;ans1 = 0;
		base = 1;
		for(int j=1;j<=10;j++){
			ans += rand()%y * base;
			ans1 += ans/base;
			base *= y;
		}
		if((ans % x == 0 ) && (ans1 %x==0)){
			cnt++;
		}
		if((ans%x)&&(ans1%x))cnt++;
		
	}
	// if(x == 3 && y == 10){
	// 	cout << ans << " " << ans1 << endl;
	// 	cout<<" cnt =" << cnt << endl;
	// }
	if(cnt==num){
		cout << "pass!" << endl;
	}
}

signed main(){
	// srand(time(0));
	// for(int i=3;i<=20;i++){
	// 	for(int j=i+1;j<=20;j++){

	// 		cout << i << " " << j <<endl;
	// 		check(i,j);
	// 	}
	// }
	int t;
	cin >> t;
	while(t--){
		int x,y;
		cin >> y >> x;
		if((y-x-1)%x==0){
			cout << "T" << endl;
		}else{
			cout <<"F" << endl;
		}
	}
}