#include<iostream>
using namespace std;

int power(int a, int b) {
    //base case
    if( b == 0 )
        return 1;

    if(b == 1)
        return a;

    //RECURSIVE CALL
    int ans = power(a, b/2);

    //if b is even
    if(b%2 == 0) {
        return ans * ans;
    }
    else {
        //if b is odd
        return a * ans * ans;
    }
}

int main() {

    int a,b;
    cout<<"\n Enter first element: ";
    cin >> a;
    cout<<"\n Enter second element: ";
    cin>>b;
    cout << endl;
    int ans = power(a,b);

    cout << "Answer is " << ans << endl;

    return 0;
}