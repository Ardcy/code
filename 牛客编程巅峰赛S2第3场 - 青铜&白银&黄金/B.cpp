#include<bits/stdc++.h>
using namespace std;
#define pb push_back 
int cnt = 0;
int cntmax = 0;
const int N = 2e5+5;
vector<int>P[N];
int arr[N];
int ans = 0;
int b[N];
class Solution {
public:
   int cnt1 = 1;
   void dfs(int head){
       arr[head] = cnt1;
       cout<< cnt1 <<endl;
       cnt1++;
       for(auto p:P[head]){
           if(p==head)continue;
           
           dfs(p);
       }
   }
    void dfs1(int head){
       
        for(auto p:P[head]){
            ans+= (b[arr[head]]^b[arr[p]]);
            cout<< b[arr[head]] <<" " << b[arr[p]] << endl;
            if(p==head)continue;
           
           dfs1(p);
       }
   }
    long long tree6(int k, vector<int>& a) {
        
        ans = 0;
        int cnt = a.size();
        cnt1 = 0;
        for(int i=0;i<cnt;i++){
            b[i]=a[i];
            int l = i;
            for(int j = 1;j<=k;j++){
                int r = i*k + j ;    
                if(r<cnt){
                	P[l].push_back(r);
                    
                }
            }
        }
        dfs(0);
        dfs1(0);
        return ans;
    }
    
};
signed main(){
	int k = 2;
	vector<int>a;
	a.push_back(1);
	a.push_back(2);a.push_back(3);
	a.push_back(4);
	a.push_back(5);
	Solution a1;
	cout<<a1.tree6(k,a)<<endl; 
}
