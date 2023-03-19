#include<iostream>
using namespace std;

int main()
{
int arr[100];
int n;
cout<<"\n How many elements?: ";
cin>>n;
int start, end;
for(int i=0; i<n; i++)
{
    cout<<"\n Enter the no: ";
    cin>>arr[i];
}

cout<<endl;

cout<<"\n Printing all the elements";
for(int i=0; i<n; i++)
{
    cout<<arr[i]<<" ";
}

start = 0;
end = n-1;
while(start<=end)
{
    int temp;
    temp=arr[start];
    arr[start]=arr[end];
    arr[end]=temp;

    start++;
    end--;
    
}
cout<<endl;
cout<<"\n Printing the reverse array elements";
cout<<endl;
for(int i=0; i<n; i++)
{
    cout<<arr[i]<<" ";
}
return 0;
}