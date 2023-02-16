#include<iostream>
using namespace std;
void merge(int* arr, int s, int e)
{
    // Finding the mid
    int mid = (s + (e-s)/2);

    int l1 = mid-s+1;
    int l2 = e-mid;

    int* first = new int(l1);
    int* second = new int(l2);

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

    int m = 0;
    int n = 0;
    int cnt = s;
    while((m<l1) && (n<l2))
    {
        if(first[m] <= second[n])
        {
            arr[cnt] = first[m];
            cnt++;
            m++;
        }
        else if(second[n] <= first[m])
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

    // deleting the dynamically allocated memory
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

    // Finding mid
    int mid = (s + (e-s)/2);

    // mergeSort left part
    mergeSort(arr, s, mid);

    // mergeSort right part
    mergeSort(arr, mid+1, e);

    // merge kar
    merge(arr, s, e);
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
    mergeSort(arr, s, e);

    cout<<"\n";
    cout<<"\n Displaying Sorted Elements";
    cout<<"\n";
    for(int i=0; i<n; i++)
    {
        cout<<arr[i]<<" -> ";
    }
return 0;
}