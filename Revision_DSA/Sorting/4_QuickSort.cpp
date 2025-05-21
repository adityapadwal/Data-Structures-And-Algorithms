#include<iostream>
using namespace std;

int partition(int*array, int s, int e)
{
    int pivot = array[s]; // choose the pivot element
    int i = s+1; // element i for finding elements greater than the pivot
    int j = e; // element j for finding elements less than the pivot

    while(i <= j)
    {
        while(i <= e && array[i] <= pivot) // find elements less than the pivot
        {
            i++;
        }

        while(j > s && array[j] > pivot) // find elements greater than the pivot
        {
            j--;
        }

        // now for the ideal position where the pivot should be, 
        // all the elements to the left are less than the pivot and
        // all the elements to the right are greater than the pivot
        if(i < j)
        {
            swap(array[i], array[j]);
            i++;
            j--;
        }
    }

    int pivotIndex = j; // ideal position where the pivot should be
    swap(array[s], array[pivotIndex]);
    return pivotIndex;
}

void quickSort(int* array, int s, int e) 
{
    // using recursion
    if(s >= e)
    {
        return;
    }

    // choose a pivot element and place it at its right place
    int p = partition(array, s, e);

    quickSort(array, s, p-1); // sort elements from 0 to pivot element
    quickSort(array, p+1, e); // sort elements from pivot+1 to end
}

int main() 
{
    cout<<"\n Menu driven program for quick sort";

    int size;
    cout<<"\n Enter the size of the array: ";
    cin>>size;

    int* array = new int [size];

    cout<<"\n Enter the elements in the array";
    for(int i=0; i<size; i++)
    {
        cout<<"\n Enter element: ";
        cin>>array[i];
    }

    quickSort(array, 0, size-1);

    cout<<"\n The sorted elements are \n";
    for(int i=0; i<size; i++)
    {
        cout<<array[i]<<" ";
    }
    return 0;
}