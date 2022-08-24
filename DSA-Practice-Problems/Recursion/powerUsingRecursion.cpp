#include<iostream>
using namespace std;

int power(int a, int b)
{
    // Base cases ( 2 )
    if(b == 0)
    {
        return 1;
    }
    if(b == 1)
    {
        return a;
    }

    int ans = power(a, b/2);
    if(b%2 == 0)
    {
        // b is even
        return ans * ans;
    }
    else
    {
        // b is odd
        return a * ans * ans;
    }
}
int main()
{
    int a;
    int b;
    cout<<"\n Power of a number using recursion! ";
    cout<<"\n Enter base number: ";
    cin>>a;
    cout<<"\n Enter index number: ";
    cin>>b;
    int ans = power(a, b);
    cout<<"\n The power of "<<a<< " and "<< b<< " is: "<<ans;
return 0;
}