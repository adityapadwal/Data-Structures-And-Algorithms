#include<iostream>
using namespace std;

int main()
{
int i; 
int  j; 
char ch; 
int n; 
cout<<"\n Enter how many lines do you want?: ";
cin>>n;
for(i=1; i<=n; i++)
{
    cout<<endl;
    for(j=1, ch = 'A'; j<=i; j++ ,ch++)
    {
        cout<<ch<<" ";
    }
}
return 0;
}
