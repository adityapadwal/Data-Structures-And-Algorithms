#include<iostream>
using namespace std;

int main()
{
int i, j, n;
cout<<"\n Kitne ka chahiye bhai? ";
cin>>n;
for(i=0; i<n; i++)
{
    cout<<endl;
    for(j=0; j<n; j++)
    {
        cout<<i+1;
    }
}
return 0;
}