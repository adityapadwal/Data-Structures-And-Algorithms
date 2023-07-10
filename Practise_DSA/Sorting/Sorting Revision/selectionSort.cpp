#include<iostream>
using namespace std;
void selectionSort(int* arr, int n)
{
    int minIndex;
    for(int i=0; i<n-1; i++)
    {
        minIndex = i;
        for(int j=i+1; j<n; j++)
        {
            if(arr[j] < arr[minIndex])
            {
                minIndex = j;
            }
        }
        swap(arr[minIndex], arr[i]);

        cout<<"\n";
        for(int i=0; i<n; i++)
        {
            cout<<arr[i]<<" ";
        }
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

    selectionSort(arr, n);

    cout<<"\n";
    cout<<"\n Displaying Sorted Elements";
    for(int i=0; i<n; i++)
    {
        cout<<arr[i]<<" ";
    } 
return 0;
}

// Rev