#include<iostream>
using namespace std;
void insertionSort(int* arr, int n)
{
    int temp;
    for(int i=1; i<n; i++)
    {
        temp = arr[i];
        int j = i-1;
        for(; j>=0; j--)
        {
            if(arr[j] > temp)
            {
                arr[j+1] = arr[j];
            }
            else
            {
                break;
            }
        }
        arr[j+1] = temp;
    }
}

int main()
{
    int n;
    cout<<"\n Enter count: ";
    cin>>n;

    int* arr = new int[n];
    for(int i=0; i<n; i++)
    {
        cout<<"Enter number: ";
        cin>>arr[i];
    } 

    insertionSort(arr, n);

    cout<<"\n";
    cout<<"\n Displaying Sorted Elements";
    for(int i=0; i<n; i++)
    {
        cout<<arr[i]<<" ";
    } 
return 0;
}