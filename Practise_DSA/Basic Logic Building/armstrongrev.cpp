#include<iostream>
using namespace std;

int main()
{
    int num;
    int sum = 0;
    int d = 0;

    cout<<"\n Enter the number: ";
    cin>>num;
    int n = num;

    while(num != 0)
    {
        d = num % 10;
        sum += d*d*d;
        num = num / 10;
    }

    if(sum == n)
    {
        cout<<"\n Armstrong Number! ";
    }
    else
    {
        cout<<"\n Not an armstrong number";
    }
return 0;
} 