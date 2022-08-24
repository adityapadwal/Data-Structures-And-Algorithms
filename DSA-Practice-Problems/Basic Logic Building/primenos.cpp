#include<iostream>
using namespace std;

int main()
{
int number;
int num=2;
int flag =1;
cout<<"\n Enter the number: ";
cin>>number;
if (number == 1)
{
    cout<<number<<" is neither prime nor composite";
    exit(0);
}
    while(num<number)
    {
        if(number%num ==0)
        {
            flag =0;
            break;  
        }
        else
        {
            num+=1;
        }
    }

    if(flag=1)
    {
        cout<<"\n The number "<<number<<" is a prime number";
    }
    else
    {
        cout<<"\n The number "<<number<<" is not a prime number";
    }

return 0;
}