// ******************Merging of two sorted arrays************************
#include<iostream>
using namespace std;

int merge(int arr1[], int m, int arr2[], int n, int arr3[])
{
    int i = 0; 
    int j = 0;
    int x=0;
    while(i< 5 && j < 3 )
    {
        if(arr1[i] < arr2[j])
        {
            arr3[x]=arr1[i];
            i++;
            x++;
        }
        else if(arr1[i] > arr2[j])
        {
            arr3[x]=arr2[j];
            j++;
            x++;
        }
    }
    while(i < 5)
    {
        arr3[x]=arr1[i];
        i++;
        x++;
    }
    while(j< 3)
    {
        arr3[x]=arr2[j];
        j++;
        x++;
    }
    
    cout<<"\n Printing the merger sorted array! "<<endl;
    for(int i=0; i<8; i++)
    {
        cout<<arr3[i]<<" ";
    }
}

int main()
{

int arr1[5]={1, 3, 5, 7, 9};
int arr2[3]={2, 4, 6};
int arr3[8]={0};  // all 8 places are initialized to 0 

merge(arr1, 5, arr2, 3, arr3);


return 0;
}