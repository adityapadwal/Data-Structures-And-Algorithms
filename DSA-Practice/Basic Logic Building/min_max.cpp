#include<iostream>
using namespace std;

int main()
{
int arr[100];
int size;
cout<<"\n How many elements? ";
cin>>size;
for(int i=0; i<size; i++)
{
    cout<<"\n Enter the number: ";
    cin>>arr[i];
}

int min=arr[0];
cout<<"\n Finding the minimum element in the array";
for(int i=0; i<size; i++)
{
    if (arr[i]<min)
    {
        min = arr[i];
    }
}
cout<<"\n The minimum element of the array is: "<<min;

int max=arr[0];
cout<<"\n Finding the Maximun element in the array";
for(int i=0; i<size; i++)
{
    if (arr[i]>min)
    {
        max = arr[i];
    }
}
cout<<"\n The minimum element of the array is: "<<max;
return 0;
}