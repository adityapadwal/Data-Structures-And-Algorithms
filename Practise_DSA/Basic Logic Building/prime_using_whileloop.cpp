#include<iostream>
using namespace std;

int main()
{
int i=2;
int n;
int flag=1;
cout<<"\n Enter a number: ";
cin>>n;
while(i<n)
{
    if(n%i==0)
    {
        flag=0;
        break;
    }
    else{
        i++;
    }
    
}
if(flag==0)
{
    cout<<"\n Not a prime number!!!";
}
else{
    cout<<"\n Prime number !!!!!";
}
return 0;
}