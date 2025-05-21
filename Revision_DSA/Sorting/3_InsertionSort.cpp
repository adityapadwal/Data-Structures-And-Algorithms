#include<iostream>
using namespace std;

void insertionSort(int* array, int size) 
{
    for(int i=1; i<size; i++)
    {
        int temp = array[i];
        int j = i-1;
        for(; j>=0; j--)
        {
            if(array[j] > temp)
            {
                array[j+1] = array[j];
            }
            else
            {
                break;
            }
        }
        array[j+1] = temp;
    }
}

int main() 
{
    cout<<"\n Menu driven program for insertion sort";

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

    insertionSort(array, size);

    cout<<"\n The sorted elements are \n";
    for(int i=0; i<size; i++)
    {
        cout<<array[i]<<" ";
    }
    return 0;
}