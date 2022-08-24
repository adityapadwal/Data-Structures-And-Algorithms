#include<iostream>
using namespace std;

void merge(int* arr, int s, int e)
{
    // finding the middle element 
    int mid = s+((e-s)/2);

    //finding the lengths of the 2 separate arrays! 
    int len1 = mid - s +1;
    int len2 = e -mid;

    // dynaically creating 1-D arrays
    int *first = new int[len1];
    int *second = new int[len2];

    // copy values
    int mainArrayIndex = s;
    for(int i=0; i<len1; i++)
    {
        first[i] = arr[mainArrayIndex++];
    }

    mainArrayIndex =mid+1;
    for(int i=0; i<len2; i++)
    {
        second[i] = arr[mainArrayIndex++];
    }
    
    // merge 2 sorted arrays 
    int index1 = 0;   //m
    int index2 = 0;   //n

    mainArrayIndex = s;

    while(index1<len1 && index2<len2)
    {
        if(first[index1] < second[index2])
        {
            arr[mainArrayIndex++] = first[index1++];
        }
        else
        {
            arr[mainArrayIndex++] = second[index2++];
        }
    }
    while(index1 < len1)
    {
        arr[mainArrayIndex++] = first[index1++];
    }
    while(index2 < len2)
    {
        arr[mainArrayIndex++] = second[index2++];
    }

    // deleteing the dynamic memory allocated 
    delete []first;
    delete []second;
}

void mergeSort(int* arr, int s, int e)
{
    // base case 
    if(s >= e)
    {
        return;
    }

    int mid = s+((e-s)/2);

    // Sorting left part
    mergeSort(arr, s, mid);

    // Sorting right part
    mergeSort(arr, mid+1, e);

    // merge
    merge(arr, s, e);

}

int main()
{
    int arr[]={5, 4, 3, 2, 1, 0};
    int n = 6;     // size of tha array arr

    mergeSort(arr, 0, n-1);
    cout<<endl;

    // Sorted array is displayed 
    cout<<endl;
    cout<<"\n Printing the sorted array!! ";
    cout<<endl;
    for(int i=0; i<n; i++)
    {
        cout<<" -> "<<arr[i];
    }
return 0;
}