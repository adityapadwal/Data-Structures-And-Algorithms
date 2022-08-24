#include<iostream>
using namespace std;

int main()
{
int i, j, k;
int num;
cout<<"\n How many lines???:";
cin>>num;
for(i=0; i<=num; i++)
{
	cout<<endl;
    for(k=1; k<=num-i; k++)
    {
        cout<<" ";
    }
    for(j=1; j<i; j++)
    {
        cout<<"*";
    }
}
return 0;
}
