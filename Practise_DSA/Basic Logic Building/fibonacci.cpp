#include<iostream>
using namespace std;

int main()
{
int a, b, sum, n;
int i;
cout<<"\n Kitna?: ";
cin>>n;
a=0; b=1;
cout<<a<<endl;
cout<<b<<endl;
for(i=0; i<n; i++)
{
    sum=a+b;
    cout<<sum<<endl;
    a=b;
    b=sum;
}
return 0;
}