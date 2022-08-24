#include<iostream>
using namespace std;

int main()
{
int min=9, max=0, num, d;
cout<<"\n Enter a number: ";
cin>>num;
while(num!=0)
{
    d=num%10;
    if(max<d)
    {
        max=d;
    }
    if(min>d)
    {
        min=d;
    }
    num=num/10;
    
}
cout<<"\n Minimum number is: "<<min;
    cout<<"\n Maximum number is: "<<max;
    
return 0;
}