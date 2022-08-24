#include<iostream>
using namespace std;

int main()
{
int n, i, j;
cout<<"\n Kitna chahiye bhai?: ";
cin>>n;
for(i=1; i<=n; i++)
{
    cout<<endl;
    for(j=1; j<=n; j++)
    {
        cout<<j;
    }
}
return 0;
}