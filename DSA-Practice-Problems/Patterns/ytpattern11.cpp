#include<iostream>
using namespace std;

int main()
{
int i, j, n, cnt=0;
char a= 'A';
cout<<"\n Enter the number: ";
cin>>n;
for(i=0; i<n; i++)
{
    cout<<endl;
    a= char('A' +n-i);
    for( j=0; j<i; j++, a++)
    {
        cout<<a;
    }
}
return 0;
}