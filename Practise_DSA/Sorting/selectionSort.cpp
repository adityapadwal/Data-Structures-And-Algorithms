#include<iostream>
using namespace std;

void selectionSort(int arr[])
{
    int i, j, min;
    for(int i=0; i<5; i++)
    {
        min=i;
        for(int j=i+1; j<5; j++)
        {
            if(arr[j] < arr[i])
            {
                min=j;
            }
        }
        if(min != i)
        {
            int temp;
            temp=arr[min];
            arr[min]=arr[i];
            arr[i]=temp;
        }
    }
}

int main()
{
int myarray[5];
cout<<"\n Enter any 5 numbers in unsorted order";
for(int i=0; i<5; i++)
{
    cin>>myarray[i];
}
selectionSort(myarray);
cout<<"\n The sorted list of th elements is: ";
for(int j=0; j<5; j++)
{
    cout<<myarray[j]<<" ";
}
return 0;
}