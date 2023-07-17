#include<iostream>
using namespace std;

int partition(int * arr, int s, int e)
{
    int pivot = arr[s];
    int i = s + 1; // Start from the element right after the pivot
    int j = e;

    while (i <= j)
    {
        while (i <= e && arr[i] <= pivot) // Find the element greater than pivot
            i++;

        while (j > s && arr[j] > pivot) // Find the element smaller or equal to pivot
            j--;

        if (i < j)
        {
            swap(arr[i], arr[j]); // Swap the elements found above
            i++;
            j--;
        }
    }

    int pivotIndex = j; // j is the correct position for the pivot element
    swap(arr[s], arr[pivotIndex]); // Place the pivot in its correct position
    return pivotIndex;
}

void quickSort(int* arr, int s, int e)
{
    // base case
    if(s >= e)
    {
        return;
    }

    int p = partition(arr, s, e);

    quickSort(arr, s, p-1);
    quickSort(arr, p+1, e);
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

    int s = 0;
    int e = n-1;
    quickSort(arr, s, e);

    cout<<"\n";
    cout<<"\n Displaying Sorted Elements";
    cout<<"\n";
    for(int i=0; i<n; i++)
    {
        cout<<arr[i]<<" -> ";
    } 
return 0;
}