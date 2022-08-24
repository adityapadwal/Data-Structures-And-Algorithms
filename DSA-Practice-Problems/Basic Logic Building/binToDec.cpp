#include<iostream>
#include<math.h>
using namespace std;

int main()
{
int n;
int i=0;
int ans=0;
cout<<"\n Enter the binary number: ";
cin>>n;
while(n!= 0)
{
    int digit = n % 10;
    if(digit==1)
    {
        ans= ans + pow(2,i);

    }
    n=n/10;
    i++;
}
cout<<"\n Decimal equivalent is: "<<ans;
return 0;
}