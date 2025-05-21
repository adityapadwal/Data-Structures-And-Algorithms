#include<iostream>
using namespace std;

void merge(int* arr, int s, int e)
{
    // 1. find mid, l1, l2 
    // 2. put elements into the 2 arrays
    // 3. Merge two sorted arrays

    int mid = (s + (e-s)/2);
    int l1 = mid - s + 1;
    int l2 = e - mid;

    int* first = new int[l1];
    int* second = new int[l2];

    int temp = s;
    for(int i=0; i<l1; i++)
    {
        first[i] = arr[temp];
        temp++;
    }

    temp = mid+1;
    for(int i=0; i<l2; i++)
    {
        second[i] = arr[temp];
        temp++;
    }

    int m = 0;
    int n = 0;
    int cnt = s;
    while(m<l1 && n<l2)
    {
        if(first[m] <= second[n])
        {
            arr[cnt] = first[m];
            m++;
            cnt++;
        }
        else if(second[n] <= first[m])
        {
            arr[cnt] = second[n];
            n++;
            cnt++;
        }
    }
    while(m<l1)
    {
        arr[cnt] = first[m];
        m++;
        cnt++;
    }
    while(n<l2)
    {
        arr[cnt] = second[n];
        n++;
        cnt++;
    }

    // delete dynamically allocated arrays
    delete []first;
    delete []second;
}

void mergeSort(int* array, int s, int e) 
{
    // base condition
    if(s >= e)
    {
        return;
    }

    // finding the mid
    int middle = (s + (e-s)/2);

    // perform mergesort on the left and right of middle
    mergeSort(array, s, middle);
    mergeSort(array, middle+1, e);

    // merge both arrays
    merge(array, s, e);
}

int main() 
{
    cout<<"\n Menu driven program for merge sort";

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

    mergeSort(array, 0, size-1);

    cout<<"\n The sorted elements are \n";
    for(int i=0; i<size; i++)
    {
        cout<<array[i]<<" ";
    }
    return 0;
}