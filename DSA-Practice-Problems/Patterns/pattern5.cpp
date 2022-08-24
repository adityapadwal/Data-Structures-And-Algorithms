#include<iostream>
using namespace std;

int main()
{
int i, j, n; 
char ch;
cout<<"\n How many lines: ";
cin>>n;
for(i=1, ch='A'; i<=n; i++)
{
    cout<<endl;
    for(j=1; j<=i; j++)
    {
        cout<<ch++<<" ";
    }
}
return 0;
}