#include<iostream>
using namespace std;
void bubbleSort(int* arr, int n)
{
    for(int i=1; i<n; i++)
    {
        for(int j=0; j<n-i; j++)
        {
            if(arr[j] > arr[j+1])
            {
                int temp;
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
        cout<<"\n";
        for(int i=0; i<n; i++)
        {
            cout<<arr[i]<<" ";
        }
    }
}

void bubbleSort_op(int* arr, int n)
{
    bool flag;
    for(int i=1; i<n; i++)
    {
        flag = false;
        for(int j=0; j<=n-i; j++)
        {
            if(arr[j] > arr[j+1])
            {
                int temp;
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;

                flag = true;
            }
        }
        cout<<"\n";
        for(int i=0; i<n; i++)
        {
            cout<<arr[i]<<" ";
        }
        if(flag == false)
        {
            break;
        }
    }
}

int main()
{
    int n;
    cout<<"\n Enter size: ";
    cin>>n;

    int *arr = new int(n);
    
    cout<<"Enter Array Elements";
    for(int i=0; i<n; i++)
    {
        cout<<"\n Enter element: ";
        cin>>arr[i];
    }

    // bubbleSort(arr, n);
    bubbleSort_op(arr, n);
    cout<<"\n ";
    cout<<"\n Displaying Sorted ELements \n";
    for(int i=0; i<n; i++)
    {
        cout<<arr[i]<<" "; 
    }
return 0;
}

/*
The above function always runs O(N2) time even if the array is sorted. 
It can be optimized by stopping the algorithm if the inner loop didn’t cause any swap. 
*/