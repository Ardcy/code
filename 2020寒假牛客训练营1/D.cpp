#include<bits/stdc++.h>
using namespace std;
#define int long long
double p[600][2];
double eps = 1e-8;
signed main(){
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>p[i][0]>>p[i][1];
    }
    double g[3];
    int cnt=0;
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            for(int k=j+1;k<=n;k++){
                
                g[0] = (p[i][0]-p[j][0])*(p[i][0]-p[j][0])+(p[i][1]-p[j][1])*(p[i][1]-p[j][1]);
                g[1] = (p[i][0]-p[k][0])*(p[i][0]-p[k][0])+(p[i][1]-p[k][1])*(p[i][1]-p[k][1]);
                g[2] = (p[k][0]-p[j][0])*(p[k][0]-p[j][0])+(p[k][1]-p[j][1])*(p[k][1]-p[j][1]);
                sort(g,g+3);
                if(g[0]+g[1]+eps<g[2]&&abs(sqrt(g[0])+sqrt(g[1])-sqrt(g[2]))>eps)cnt++;
            }
        }
    }
    cout<<cnt<<endl;
}
