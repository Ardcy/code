#include<bits\stdc++.h>
using namespace std;
int a[100050];
int main(){
    int t;
    cin>>t;
    for(int i=1;i<t;i++){
        cin>>a[i];
    }
    sort(a+1,a+t);
    a[t]=t+1;
    for(int i=2;i<=t;i++){
        if(a[i]!=a[i-1]+1)cout<<i<<endl;
    }
}
#include <iostream> 
 #include <stdio.h> 
  #include <string.h>   
  #include <stack> 
   #include <queue>  
    #include <map> 
	 #include <set>
	   #include <vector>
	     #include <math.h> 
		  #include <bitset> 
		   #include <algorithm>
		     #include <climits> 

