#include<iostream>
using namespace std;

void bubbleSort(int* array, int size) 
{
    // outer loop is for passes
    for(int i=1; i<size; i++)
    {
        bool swapped;
        // inner loop is for comparisons and swaps
        for(int j=0; j<size-i; j++)
        {
            if(array[j] > array[j+1])
            {
                swapped = true;
                swap(array[j], array[j+1]);
            }
        }

        if(swapped == false)
        {
            break;
        }
    }
}

int main() 
{
    cout<<"\n Menu driven program for bubble sort";

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

    bubbleSort(array, size);

    cout<<"\n The sorted elements are \n";
    for(int i=0; i<size; i++)
    {
        cout<<array[i]<<" ";
    }
    return 0;
}