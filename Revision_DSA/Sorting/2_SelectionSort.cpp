#include<iostream>
using namespace std;

void selectionSort(int* array, int size) 
{
    int minIndex;

    for(int i=0; i<size-1; i++)
    {
        minIndex = i;
        for(int j=i+1; j<size; j++)
        {
            if(array[j] < array[minIndex])
            {
                minIndex = j;
            }
        }

        swap(array[i], array[minIndex]);
    }
}

int main() 
{
    cout<<"\n Menu driven program for selection sort";

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

    selectionSort(array, size);

    cout<<"\n The sorted elements are \n";
    for(int i=0; i<size; i++)
    {
        cout<<array[i]<<" ";
    }
    return 0;
}