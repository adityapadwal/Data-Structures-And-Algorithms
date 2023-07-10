#include<iostream>
#include<stack>
using namespace std;

int main()
{
    stack<int>s;
    string p = "Aditya Padwal";
    // pushing all th elements of the stack! 
    for(int i=0; i<p.length(); i++)
    {
        s.push(p[i]);
    }

    string ans ="";
    //popping and displaying all the elements of the stack
    while(! s.empty())
    {
        char ch = s.top();
        ans.push_back(ch);
        s.pop();
    }

    cout<<"\n The reversed String is: "<<ans;
return 0;
}

