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
    for(cnt=i,j=1; j<=i; j++, cnt++)
    {
        cout<<cnt<<" ";
    }
    
}
return 0;
}