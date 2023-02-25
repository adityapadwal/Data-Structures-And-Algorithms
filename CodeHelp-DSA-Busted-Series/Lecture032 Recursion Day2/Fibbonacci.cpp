#include<iostream> 
using namespace std;


int main() {

    //Base Case
        if( n==0)
        {
            return 0;
        }
        
        if( n==1 )
        {
            return 1;
        }
        
        
        //Recursive relation
        int ans = fib(n-1) + fib(n-2);
        
        return ans;


    return 0;
}