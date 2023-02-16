#include<iostream>
using namespace std;

void merge(int* arr, int s, int e)
{
    //Finding the mid
    int mid = s+((e-s)/2);

    // finding the lengths of the left and the right parts
    int l1 = mid-s+1;
    int l2 = e-mid;

    // dynamicall creating 1-D arrays
    int* first = new int[l1];
    int* second = new int[l2];

    //copying the values in the dynamically created array
    int index = s;
    for(int i=0; i<l1; i++)
    {
        first[i] = arr[index];
        index++;
    }    

    index = mid+1;
    for(int i=0; i<l2; i++)
    {
        second[i] = arr[index];
        index++;
    }

    //merging of two sorted arrays
    int m=0;
    int n=0;
    int cnt=s;
    while(m<l1 && n<l2)
    {
        if(first[m] < second[n])
        {
            arr[cnt] = first[m];
            cnt++;
            m++;
        }
        else if(first[m] > second[n])
        {
            arr[cnt] = second[n];
            cnt++;
            n++;
        }
    }
        while(m<l1)
        {
            arr[cnt] = first[m];
            cnt++;
            m++;
        }
        while(n<l2)
        {
            arr[cnt] = second[n];
            cnt++;
            n++;
        }
        
    // deleteing the dynamic memory allocated (i.e, 1-D array)
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

    //Finding the mid
    int mid = s+((e-s)/2);

    //left wala part sambhal lo
    mergeSort(arr, s, mid);

    //right wala part sambhal lo 
    mergeSort(arr, mid+1, e);

    //merge wala function! 
    merge(arr, s, e);
}
int main()
{
    int arr[]={5,4,3,2,1,0};
    int n = 6;

    mergeSort(arr, 0, n-1);

    cout<<endl;
    cout<<endl;
    cout<<"\n Displaying the sorted array! ";
    for(int i=0; i<n; i++)
    {
        cout<<" -> "<<arr[i];
    }
return 0;
}