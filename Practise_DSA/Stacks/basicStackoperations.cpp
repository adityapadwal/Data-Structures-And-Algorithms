#include<iostream>
#include<stack>
using namespace std;

int main()
{
    stack<int>s;

    s.push(2);
    s.push(3);

    s.pop();

    cout<<"\n Printing top element: "<<s.top();
    cout<<"\n Empty hai kya?: "<<s.empty();
return 0;
}