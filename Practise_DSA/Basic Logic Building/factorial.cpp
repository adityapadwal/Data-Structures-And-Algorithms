#include<iostream>
using namespace std;

int factorial(int n)
{
    if(n==0)     // base case 
    {
        return 1;
    }


    return n * factorial(n-1);    // recursive relation
}
int main()
{
int n;
cout<<"\n Enter the number: ";
cin>>n;
cout<<"\n Factorrial of "<<n<<" is: "<<factorial(n);
return 0;
}