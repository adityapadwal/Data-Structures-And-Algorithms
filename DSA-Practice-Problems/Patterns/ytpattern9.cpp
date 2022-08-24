#include<iostream>
using namespace std;

int main()
{
int i, j, n;
char a= 'A';
cout<<"Kitna?: ";
cin>>n;
for(i=1; i<=n; i++)
{
    cout<<endl;
    for(j=1; j<=i; j++)
    {
        cout<<a;
    }
    a++;
}
return 0;
}