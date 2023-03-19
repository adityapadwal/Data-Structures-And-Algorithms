// merging of two sorted arrays! 

#include<iostream>
using namespace std;
void mergeSort(int* arr1, int m, int* arr2, int n, int*arr3)
{
    int i=0;
    int j=0;
    int x =0;

    while(i<m && j<n)
    {
        if(arr1[i] < arr2[j])
        {
            arr3[x] = arr1[i];
            i++;
            x++;
        }
        else if(arr1[i] > arr2[j])
        {
            arr3[x] = arr2[j];
            j++;
            x++;
        }
    }
    
    while(i<m)
    {
        arr3[x] = arr1[i];
        i++;
        x++;
    }
    while(j<n)
    {
        arr3[x] = arr2[j];
        j++;
        x++;
    }
}

int main()
{
    int arr1[6]={1,5,9,11,17,19};
    int arr2[8] = {2,6,8,10,18,22,26,32};
    int arr3[14] = {0};

    mergeSort(arr1, 6, arr2, 8, arr3);

    cout<<"\n Printing the soretd array!! ";
    cout<<endl;

    for(int i=0; i<14; i++)
    {
        cout<<" -> "<<arr3[i];
    }

return 0;
}
