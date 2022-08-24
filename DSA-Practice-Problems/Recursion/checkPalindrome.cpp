#include<iostream>
using namespace std;
bool checkPalindrome(string& str, int n, int i, int j)
{
    // base case 
    if(i > j)
    {
        return true;
    }
    if(str[i] == str[j])
    {
        i++;
        j--;
        checkPalindrome(str, n, i, j);
    }
    else
    {
        return false;
    } 
}
int main()
{
string str="abca";
int n = str.length();
bool ans = checkPalindrome(str, n, 0, str.length()-1);
if(ans != false)
{
    cout<<"\n Palindrome! ";
}
else
{
    cout<<"\n Not a Palindrome! ";
}
return 0;
}