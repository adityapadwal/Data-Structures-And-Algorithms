#include<iostream>
using namespace std;

int main()
{
int arr[1000];
int n;
cout<<"\n How many elements?: ";
cin>>n;
for(int i=0; i<n; i++)
{
    cout<<"\n Enter the element: ";
    cin>>arr[i];
}
int sum = 0;
for(int j=0; j<n; j++)
{
    sum += arr[j];
}
cout<<"\n The sum of all the array elements is: "<<sum;
return 0;
}