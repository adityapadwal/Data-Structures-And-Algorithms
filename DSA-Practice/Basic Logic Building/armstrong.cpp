// Armstrong number = sum of the cube of its digits

#include<iostream>
using namespace std;

int main()
{
int num;
int n;
int d = 0;
int sum =0;
cout<<"\n Enter a number: ";
cin>>num;
n=num;
while(num!=0)
{
    d = num % 10;
    sum = sum + (d*d*d);
    num=num/10;
}
if(sum==n)
{
    cout<<"\n Armstrong number";
}
else{
    cout<<"\n Not an armstrong number";

}
return 0;
}
