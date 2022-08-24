#include<iostream>
using namespace std;

void printArray(int arr[], int n)
{
    for(int i=0; i<n; i++)
    {
        cout<<arr[i]<<" ";
    }
}
void swapAlternate(int arr[], int size)
{
    for(int i=0; i<size; i+=2)
    {
        if (i+1 < size)
        {
            swap(arr[i], arr[i+1]);  // inbuilt STL function 
        }
    }
}
int main()
{
int arr1[5]={1,2,3,4,5};
int arr2[6]={10,11,12,13,14,15};
cout<<endl;
cout<<"\n Printing all the elements: "<<endl;
printArray(arr1, 5);
cout<<endl;
printArray(arr2, 6);

cout<<endl;

cout<<"\n Printing the swapped array: "<<endl;
swapAlternate(arr1, 5);
printArray(arr1, 5);
cout<<endl;
swapAlternate(arr2, 6);
printArray(arr2, 6);

return 0;
}