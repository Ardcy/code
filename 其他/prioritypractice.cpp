//C++ ���ȶ����꾿
#include<bits/stdc++.h>
using namespace std;
/*
	��ʹ�ò���  top empty size push emplace pop swap
	�����ȼ��ߵ����ڶ���ǰ�� ���ȳ���
	priority<int,vector<int>,less<int> > 
	
*/ 
/*
//

priority_queue::swap �÷� 
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
