#include<iostream>
using namespace std;

int gcd(int a, int b)
{
    if(a==0)
    {
        return b;
    }
    if(b==0)
    {
        return a;
    }
    while(a!=b)
    {
        if(a>b)
        {
            a = a - b;
        }
        else
        {
            b = b - a;
        }
    }
    return a;
}
int main()
{
int a, b;
cout<<"\n Enter two numbers: ";
cout<<"\n First number: ";
cin>>a;
cout<<"\n Second number: ";
cin>>b;
int ans = gcd(a,b);
cout<<"\n The GCD of the two numbers "<<a<<" and "<<b<<" is: "<<ans;

return 0;
}