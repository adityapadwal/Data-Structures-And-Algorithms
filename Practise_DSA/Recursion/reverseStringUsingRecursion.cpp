#include<iostream>
#include<string.h>
using namespace std;

void reverse(char ch[], int n, int i, int j)
{

    //base case
    if(i >= j)
    {
        return;
    }
    swap(ch[i], ch[j]);
    i++;
    j--;
    reverse(ch, n, i, j);
}
int main()
{
    int n = 6;
    int i=0; 
    int j = n-1;
    char ch[]={'a', 'b', 'c', 'd', 'e', 'f'};
    reverse(ch, n, i, j);
    cout<<"\n The reversed character array is: "<<ch;
return 0;
}