#include<iostream>
using namespace std;

int main()
{
char ch;
cout<<"Enter the character: ";
cin>>ch;
if(ch>=97 && ch<=122)
{
    cout<<"\n The entered character is a lowercase letter!";
}
else if(ch>=65 && ch<=90)
{
    cout<<"\n The entered character is an uppercase letter!";
}
else if(ch>=48 && ch<=57)
{
    cout<<"\n The entered value is a number between 0 to 9 !";
}
else
{
    cout<<"\n The entered value is something else!!!";
}
return 0;
}