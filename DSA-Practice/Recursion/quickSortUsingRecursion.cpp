#include<iostream>
using namespace std;

int partition(int* arr, int s, int e)
{
    int pivot = arr[s];            // Taking the first element as the pivot element
    int cnt = 0;
    for(int i=s+1; i<=e ; i++)
    {
        if(arr[i] <= pivot)
        {
            cnt++;
        }
    }

    //place pivot at right position 
    int pivotIndex = s + cnt;
    swap(arr[pivotIndex], arr[s]);

    //left and right swap kardo 
    int i=s, j=e;
    while(i< pivotIndex && j>pivotIndex)
    {
        while(arr[i] <= arr[pivotIndex])
        {
            i++;
        }
        while(arr[j] > arr[pivotIndex])
        {
            j--;
        }
        if(i<pivotIndex && j>pivotIndex)
        {
            swap(arr[i], arr[j]);
            i++;
            j--;
        }
    }
    return pivotIndex;
}
void quickSort(int* arr, int s, int e)
{
    //base case 
    if(s >= e)
    {
        return;
    }
    // partition
    int p = partition(arr, s, e);

    //leftwala sort karado
    quickSort(arr, s, p-1);

    //rightwala sort karado 
    quickSort(arr, p+1, e);

}
int main()
{
    int arr[]={3,4,1,2,6,9,8,0,34,21,45,89,22};
    int n = 13;
    quickSort(arr, 0, n-1);
    cout<<"\n Displaying the sorted array! ";
    cout<<endl;
    for(int i=0; i<n; i++)
    {
        cout<<" -> "<<arr[i];
    }
return 0;
}