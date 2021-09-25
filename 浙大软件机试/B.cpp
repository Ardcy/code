#include<bits/stdc++.h>
using namespace std;
const int N = 2e5+1;
int A[N],B[N],C[N];

int ans1 = 0,ans2 = 0,ans3 = 0;
int ans = 2e7+3;
int f(int a1,int b1,int c1) {
	return abs(a1-b1)+abs(a1-c1)+abs(b1-c1);
}
signed main() {
	int a,b,c;
	cin>>a>>b>>c;
	for(int i=1; i<=a; i++)cin>>A[i];
	for(int j=1; j<=b; j++)cin>>B[j];
	for(int i=1; i<=c; i++)cin>>C[i];
	sort(A+1,A+a+1);
	sort(B+1,B+b+1);
	sort(C+1,C+c+1);
	for(int i=1; i<=a; i++) {
		int t1 = upper_bound(B+1,B+b+2,A[i])-B;
		int t2 = lower_bound(B+1,B+b+2,A[i])-B;
		int o1 = upper_bound(C+1,C+c+2,A[i])-C;
		int o2 = lower_bound(C+1,C+c+2,A[i])-C;
		for(int j=max(t2-20,1); j<=min(b,t1+15); j++) {
			for(int k=max(o2-15,1); k<=min(c,o1+15); k++) {
				int p  = f(A[i],B[j],C[k]);
				if(p<=ans) {
					ans=p;
					ans1=A[i];
					ans2=B[j];
					ans3=C[k];
				}
			}
		}
	}
	for(int i=1; i<=b; i++) {

		int t1 = upper_bound(A+1,A+a+2,B[i])-A;
		int t2 = lower_bound(A+1,A+a+2,B[i])-A;
		int o1 = upper_bound(C+1,C+c+2,B[i])-C;
		int o2 = lower_bound(C+1,C+c+2,B[i])-C;
		for(int j=max(t2-20,1); j<=min(a,t1+15); j++) {
			for(int k=max(o2-15,1); k<=min(c,o1+15); k++) {
				int p  = f(A[j],B[i],C[k]);
				if(p<=ans) {
					ans=p;
					ans1=A[j];
					ans2=B[i];
					ans3=C[k];
				}
			}
		}
	}

	for(int i=1; i<=c; i++) {
		int t1 = upper_bound(B+1,B+b+2,C[i])-B;
		int t2 = lower_bound(B+1,B+b+2,C[i])-B;
		int o1 = upper_bound(A+1,A+a+2,C[i])-A;
		int o2 = lower_bound(A+1,A+a+2,C[i])-A;
		for(int j=max(t2-20,1); j<=min(b,t1+15); j++) {
			for(int k=max(o2-15,1); k<=min(a,o1+15); k++) {
				int p  = f(C[i],B[j],A[k]);
				if(p<=ans) {
					ans=p;
					ans1=A[k];
					ans2=B[j];
					ans3=C[i];
				}
			}
		}
	}
	cout<<"MinD("<<ans1<<", "<<ans2<<", "<<ans3<<") = "<<ans<<endl;
}
