#include<iostream>
using namespace std;

int main()
{
int num;
int n;
int d=0;
int rev;
cout<<"\n Enter a number: ";
cin>>num;
num=n;
rev=0;
while(num!=0)
{
    d=num%10;
    rev=rev*10+d;
    num=num/10;
}
cout<<"\n Reversed number is: "<<rev;
/*
if(rev==n)
{
    cout<<"\n The number is a palindrome"<<n;
}
else
{
    cout<<"\n It is not a palindrome"<<n;
}
*/
return 0;
}
