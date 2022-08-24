#include<iostream>
using namespace std;

int main()
{
int i, j, k, n, cnt;
cout<<"\n Enter how many lines?";
cin>>n;
for(i=1, cnt=n ; i<=n; i++, cnt--)
{
    cout<<endl;
    for(k=0; k<i; k++)
    {
        cout<<" ";
    }
    for(j=1; j<=(cnt*2-1); j++)
    {
        cout<<"*";
    }
}
return 0;
}