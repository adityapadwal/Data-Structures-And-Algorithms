#include<iostream>
using namespace std;

int getSum(int arr[], int n)
{   
    int i=0;
    int sum = 0;
    //base case 
    if(n==0)
    {
        return 0;
    }
    if(n==1)
    {
        return arr[0];
    }
    
        sum+= arr[n-1] + getSum(arr, n-1);  // recursive relation 
        return sum;
}
int main()
{
int arr[100]={0};
int n;
cout<<"\n Enter the array elements: ";
cin>>n;
for(int i=0; i<n; i++)
{
    cout<<"\n Enter number: ";
    cin>>arr[i];
}

int ans = getSum(arr, n);
cout<<"\n The sum of the array elements is: "<<ans;
return 0;
}