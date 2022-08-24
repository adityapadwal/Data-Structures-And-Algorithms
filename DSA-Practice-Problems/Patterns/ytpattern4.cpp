#include<iostream>
using namespace std;

int main()
{
int n, i, j;
cout<<"\n Kitna?: ";
cin>>n;
for(i=1; i<=n; i++)
{
    cout<<endl;
    for(j=1; j<=n; j++)
    {
        cout<<n-j+1;
    }
}
return 0;
}