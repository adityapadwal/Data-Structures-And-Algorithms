#include<iostream>
using namespace std;

int main()
{
int n;
int i, j;
cout<<"\n Enter how many Lines do you want: ";
cin>>n;
for(i=1; i<=n; i++)
{
    cout<<endl;
    for(j=1; j<=i; j++)
    {
        cout<<j<<" ";

    }
}
return 0;
}