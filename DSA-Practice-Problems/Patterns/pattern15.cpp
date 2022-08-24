#include<iostream>
using namespace std;

int main()
{
int i, j, k;
int num;
cout<<"\n How many lines???:"; //5
cin>>num;
for(i=1; i<=num; i++)
{
	cout<<endl;
    for(k=1; k<i; k++)
    {
        cout<<" ";
    }
        for(j=k; j<=num; j++)
        {
            cout<<"*";
        }
}
return 0;
}
