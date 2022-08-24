#include<iostream>
using namespace std;

int main()
{
int arr[10];
int n;
cout<<"Elements?: ";
cin>>n;
for(int i=0; i<n; i++)
{
    cout<<"Daalo: ";
    cin>>arr[i];
}
cout<<"\n \n Linear Search";
int key; 
int flag=0;
cout<<"\n Enter the key: ";
cin>>key;
for(int i=0; i<n; i++)
{
    if(arr[i]==key)
    {
        cout<<"Key found! ";
        flag=1;
    }
    else
    {
        flag=0;
    }
}
if(flag=0)
{
    cout<<"\n Key not found!!!";
}

return 0;
}