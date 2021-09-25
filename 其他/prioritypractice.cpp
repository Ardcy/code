//C++ 优先队列详究
#include<bits/stdc++.h>
using namespace std;
/*
	可使用操作  top empty size push emplace pop swap
	让优先级高的排在队列前面 优先出队
	priority<int,vector<int>,less<int> > 
	
*/ 
/*
//

priority_queue::swap 用法 
#include <iostream>       // std::cout
#include <queue>          // std::priority_queue
int main ()
{
  std::priority_queue<int> foo,bar;
  foo.push (15); foo.push(30); foo.push(10);
  bar.push (101); bar.push(202);

  foo.swap(bar);

  std::cout << "size of foo: " << foo.size() << '\n';
  std::cout << "size of bar: " << bar.size() << '\n';

  return 0;
}
*/
int main(){
	priority_queue<pair<int,int> >a;
	pair<int,int>b(1,2);
	pair<int,int>c(1,3);
	pair<int,int>d(2,5);
	a.push(d);
	a.push(c);
	a.push(b);
	cout<<a.size()<<endl;
	while(!a.empty()){
		cout<< a.top().first<<' '<<a.top().second<<endl;
		a.pop();
	}
}
