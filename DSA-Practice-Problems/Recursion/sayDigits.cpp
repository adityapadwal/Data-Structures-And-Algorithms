#include<iostream>
#include<string.h>
using namespace std;

void sayDigits(string arr[], int n)
{
    if(n==0)
    {
        return;
    }

    int digit = n % 10;
    n = n / 10;
    
    sayDigits(arr, n);

    cout<<" -> "<<arr[digit];
}

int main()
{
    string arr[10] = {"Zero", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine"};
    int n;
    cout<<"\n Enter Number: ";
    cin>>n;

    sayDigits(arr, n);

return 0;
}