#include<iostream>
using namespace std;

int main()
{
int n, i, j, cnt;
cout<<"Kitna?: ";
cin>>n;

for(i=1; i<=n; i++)
{
    cout<<endl;
    for(j=i; j>=1; j--)
    cout<<j<<" ";
}
return 0;
}