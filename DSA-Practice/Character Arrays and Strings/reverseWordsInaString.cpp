#include<iostream>
// #include<bits/std++.h>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

void reverseWords(string s)
{
    int j=0;
    for(int i=0;i<=s.length();++i)
    {
        // if(s[i]==' ' || s[i]=='\0')
        // {
        //     std::reverse(s.begin()+j,s.begin()+i);
        //     j=i+1;
        // }
    }
    std::reverse(s.begin(),s.end());
}
int main()
{
string s;
cout<<"\n Enter the string: ";
cin>>s;
reverseWords(s);
std::reverse(s.begin(), s.end());
cout<<s;
return 0;
}