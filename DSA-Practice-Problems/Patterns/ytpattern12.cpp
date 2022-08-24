#include<iostream>
using namespace std;

int main()
{
int i, j, k;
int num;
cout<<"\n How many lines???:";
cin>>num;
for(i=0; i<num; i++)
{
	cout<<endl;
    for(k=1; k<=i; k++)
    {
        cout<<" ";
    }
    for(j=1; j<num; j++ )
    {
        cout<<j;
    } 
}
return 0;
}
