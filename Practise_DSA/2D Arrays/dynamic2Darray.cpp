// *****************  NOT WORKING *************************

#include<iostream>
using namespace std;

int main()
{
    int n;
    cout<<"\n Enter array size: ";
    cin>>n;

    int** arr = new int*[n];

    for(int i=0; i<n; i++)
    {
        arr[i] = new int[n];
    }

    // creation done !

    //taking array 
    cout<<"\n Enter all the 2D array elements ";
    for(int i=0; i<n; i++)
    {
        for(int j=0; i<n; j++)
        {
            cout<<"\n Enter number: ";
            cin>>arr[i][j];
        }
    }

    //Displaying array 
    cout<<"\n displaying the array. ";
    for(int i=0; i<n; i++)
    {
        cout<<endl;
    
        for(int j=0; i<n; j++)
        {
            cout<<arr[i][j]<<"  ";
        }
    }

    //releasing memory 
     for(int i=0; i<n; i++)
     {
         delete [] arr[i];
     }
    delete[] arr;
return 0;
}