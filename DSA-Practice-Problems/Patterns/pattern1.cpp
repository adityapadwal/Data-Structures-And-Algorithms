#include<iostream>
using namespace std;

int main()
{
int n;
int i,j;
cout<<"\n How any lines?: ";
cin>>n;
for(i=1; i<=n; i++)
{
    cout<<endl;
    for(j=0; j<i; j++)
    {
        cout<<"*";
    }
}
return 0;
}