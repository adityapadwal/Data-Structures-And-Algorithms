#include<iostream>
using namespace std;

int main()
{
int arr[6]={6, 5, 4, 3, 2, 1};
int i, j;
cout<<"\n Printing the given sorted array: ";
for(int i=0; i<6; i++)
{
    cout<<" "<<arr[i];
}
for(int i=0; i<6; i++)
{
    for(int j=i+1; j<6;j++)
    {
        if(arr[i]>arr[j])
        {
        // int temp;
        // temp=arr[i];
        // arr[i]=arr[j];
        // arr[j]=temp;
        swap(arr[i], arr[j]);
        }
    }
}
cout<<"\n Printing the sorted array: ";
for(int i=0; i<6; i++)
{
    cout<<arr[i]<<" ";
}
return 0;
}