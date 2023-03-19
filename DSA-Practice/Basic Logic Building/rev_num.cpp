#include<iostream>
using namespace std;

int main()
{
int num;
int n;
int d = 0;
int rev = 0;
cout<<"\n Enter a number: ";
cin>>num;
while(num!=0)
{
    d = num % 10;
    rev = rev * 10 + d;
    num=num/10;
}
cout<<"\n The reversed number is: "<<rev;

return 0;
}
