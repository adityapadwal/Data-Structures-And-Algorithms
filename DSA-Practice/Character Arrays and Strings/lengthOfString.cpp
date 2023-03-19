#include<iostream>
using namespace std;

void getName(char name[])
{
    cout<<"\n Enter your name: ";
    cin>>name;
}
void nameLength(char name[])
{
    int count =0;
    int i=0;
    cout<<"\n Your name is: ";
    while(name[i] != '\0')
    {
        count++;
        cout<<name[i];
        i++;
    }
    cout<<"\n Length of the string is: "<<count;

    
}
void revName(char name[], int count)
{
    int s=0;
    int e = count-1;
    while(s<e)
    {
        swap(name[s++], name[e--]);
    }
}
int main()
{
    string a = "Aditya";
    cout<<a;
    char name[100];
    getName(name);
    nameLength(name);
    revName(name, 6);

    cout<<"\n Reversed Name is: "<<name;
    return 0;
}