#include<iostream>
#include<string>
#include<cstring>
using namespace std;

int main()
{
char a[20];
cout<<"\n Enter string a: ";
cin.getline(a, 40);
// cin>>a;
char b[20];
cout<<"\n Enter string b: ";
cin.getline(b, 40);
cout<<"\n Comparison is: "<<strcmp(a, b);
cout<<endl;
cout<<"\n The first string you entered is: "<<a;
cout<<"\n The second string you entered is: "<<b;
cout<<"\n Findind length of the first string: ";
int x = strlen(a);
cout<<"Length of the first string is: "<<x;
cout<<"\n Findind length of the second string: ";
int y = strlen(b);
cout<<"Length of the second string is: "<<y;
return 0;
}