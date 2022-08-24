#include<iostream>
#include<string>
#include<cstring>
using namespace std;

int main()
{
char a[20];
cout<<"\n Enter a string: ";
cin.getline(a, 40);
char b[20];
cout<<"\n Enter b string: ";
cin.getline(b, 40);
cout<<"\n Comparison is: "<<strcmp(a, b);
cout<<endl;
cout<<"\n The string you entered is: "<<a;
cout<<"\n Findind length of the string: ";
int x = strlen(a);
cout<<"Length of the string is: "<<x;
return 0;
}