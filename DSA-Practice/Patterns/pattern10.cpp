#include<iostream>
using namespace std;

int main()
{
int n, i, j;
int num;
cout<<"\n How many lines?: ";
cin>>num;
for(i=1; i<=num; i++)
{
    cout<<endl;
    for(j=1; j<=i; j++)
    {
        if(j%2 == 0)
        {
            cout<<1<<" ";
        }
        
        else
        {
            cout<<0<<" ";
        }
    }
}
return 0;
}