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
    for(j=0, cnt=i; j<i; j++, cnt++)
    {
        cout<<char(a+ cnt);
    }
}
return 0;
}