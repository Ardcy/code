#include <bits/stdc++.h>
using namespace std;
#define int long long
int n, a[1000005], top;
int b[1000005], ans[1000005], srt[1000005], mx;

signed main() {
	int t;
	cin>>t;
	while(t--){
		cin>>n;
	    for (int i = 1; i <= n; i++) {
	       	cin>>a[i];
	       	ans[i]=0;
	       	b[i]=0;
	       	srt[i]=0;
	    }
	    int top=0;
	    int mx=0;
	    for (int i = 1; i <= n; i++) {
	        if (a[i] == -1) {
	            ans[i] = i * 1000005;
	            b[++top] = ans[i];
	        } else {
	            if (a[i] > top) {
	                ans[i] = i * 1000005;
	                b[++top] = ans[i];
	            } else {
	                ans[i] = b[a[i]] - 1;
	                b[top = a[i]] = ans[i];
	            }
	        }
	    }
	    for (int i = 1; i <= n; i++) srt[i] = ans[i];
	    sort(srt + 1, srt + n + 1);
	    for (int i = 1; i <= n; i++) ans[i] = lower_bound(srt + 1, srt + n + 1, ans[i]) - srt;
	    for (int i = 1; i <= n; i++) cout<<ans[i]<<" ";
	    cout<<endl;
	}
    return 0;
}
