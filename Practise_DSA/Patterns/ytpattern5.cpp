#include<iostream>
using namespace std;

int main()
{
int n, i, j, cnt=1;
cout<<"\n Kitna?: ";
cin>>n;
for(i=1; i<=n; i++)
{
    cout<<endl;
    for(j=1; j<=i; j++)
    {
        cout<<cnt++<<" ";
    }
}
return 0;
}
