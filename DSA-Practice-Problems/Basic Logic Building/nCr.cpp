#include<iostream>
using namespace std;

int factorial(int a)
{
    int fact = 1;
    for(int i=1; i<=a; i++)
    {
        fact = fact * i;
    }
    return fact;
}
int nCr(int n, int r)
{
    int nume = factorial(n);
    int deno = factorial(r) * factorial(n-r);

    int ans= nume / deno;
    return ans;
}
int main()
{
int n, r;
cout<<"\n Enter the value of n: ";
cin>>n;
cout<<"\n Enter the value of r: ";
cin >>r;

int answer= nCr(n, r);
cout<<"\n The value of nCr is: "<<answer;
return 0;
}