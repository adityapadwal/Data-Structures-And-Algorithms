#include<iostream>
using namespace std;

void sort01(int arr[], int n)
{
    int i, j;
    i=0; 
    j=n-1;
    while(i<j)
    {
        while(arr[i]==0)
        {
            i++;
        }
        while(arr[j]==1)
        {
            j--;
        }

        //now arr[i]==1 and arr[j]==0 matlab swap kar 
        swap(arr[i], arr[j]);//swap is an inBuilt function. No need to add any header file for it
        i++;
        j--;
    }
}
void printArray(int arr[], int n)
{
    cout<<"\n Printing the sorted array: ";
    cout<<endl;
    for(int i=0; i<n; i++)
    {
        cout<<arr[i]<<" ";
    }
}
int main()
{
int i,j;
int arr[10];
for(i=0; i<10; i++)
{
    cout<<"\n Enter the number: ";
    cin>>arr[i];
}
sort01(arr, 10);
printArray(arr, 10);
return 0;
}