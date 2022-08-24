#include<iostream>
#include<bits/std++.h>
using namespace std;

void reverseWords(string s)
{
    int j=0;
    for(int i=0;i<=s.length();++i)
    {
        if(s[i]==' ' || s[i]=='\0')
        {
            reverse(s.begin()+j,s.begin()+i);
            j=i+1;
        }
    }
    reverse(s.begin(),s.end());
}
int main()
{
string s;
cout<<"\n Enter the string: ";
cin>>s;
reverseWords(s);
reverse(str.begin(), str.end());

return 0;
}