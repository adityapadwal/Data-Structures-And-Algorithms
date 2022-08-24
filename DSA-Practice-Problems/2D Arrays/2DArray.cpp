#include<iostream>
#include<vector>
using namespace std;

void largestRowSum(int arr[3][3], int n, int m)
{
    vector<int>a;
    
    for(int i=0; i<n; i++)
    {
        int sum=0;
        for(int j=0; j<m; j++)
        {
            sum += arr[i][j];
        }
        a.push_back(sum);

    }
    int min = -1000;
    for(int i=0; i<a.size(); i++)
    {
        if(a[i]>min)
        {
            swap(a[i], min);
        }
    }
    cout<<"\n The Largest Row sum is: "<<min;

}
int main()
{
int i;
int j;
// int n;
// int m;

// cout<<"\n Enter number of Rows: ";
// cin>>n;
// cout<<"\n Enter number of columns: ";
// cin>>m;
int arr[3][3]; // ghatiya practise 
for(i=0; i<3; i++)
{
    for(j=0; j<3; j++)
    {
        cout<<"\n Enter the element ["<<i <<"] ["<<j<<"] : ";
        cin>>arr[i][j];
    }
}
cout<<"\n Displaying the matrix "<<endl;
for(i=0; i<3; i++)
{
    cout<<endl;
    for(j=0; j<3; j++)
    {
        cout<<arr[i][j]<<" ";
    }
}

largestRowSum(arr, 3, 3);

return 0;
}