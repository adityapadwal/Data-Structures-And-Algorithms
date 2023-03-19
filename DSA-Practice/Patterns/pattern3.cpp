#include<iostream>
using namespace std;

int main()
{
int num;
int i, j;
int cnt;
cout<<"\n Enter how many lines?: ";
cin>>num;
for(cnt=1, i=1; i<=num; i++)
{
    cout<<endl;
    for(j=1; j<=num; j++)
    {
        cout<<cnt++<<"\t";
    }
}
return 0;
}