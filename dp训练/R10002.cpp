#include<bits/stdc++.h>
using namespace std;
int a[105000];
int main(){
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);

	int q;
	cin>>q;
	for(int i=1;i<=q;i++){
		int d;
		cin>>d;
		int l=1,r=n;
		int mid = (l+r)/2;
		
		if(a[1]>d)cout<<0<<endl;
		if(a[n]<d)cout<<n<<endl;
		while(a[l]<=d&&a[r]>d){
			if(a[mid]>d){
				r=mid;
			}
			else{
				l=mid;
			}
			mid = (l+r)/2;
			if(r-l==1){
				
				cout<<l<<endl;
				break;
			}
		}
		
	}
}
