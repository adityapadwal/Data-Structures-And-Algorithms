#include<iostream>
#include<math.h>
using namespace std;

class Solution {
public:
    int bitwiseComplement(int n) {
        
        int m = n;
        int mask = 0;
        
        if(n == 0)
            return 1;
        
        while( m!=0) {
            mask = (mask << 1) | 1;
            m = m >> 1;
        }
        
        int ans = (~n) & mask;
        
        return ans;
        
    }
};

// Easier solution, use this**

class Solution {
public:
    int bitwiseComplement(int n) {

        //one complement of x is (2^n)-m-1   // V.V. Important formula

        if(n==0)
        return 1;

        int count=0;
        int d;
        int m=n;
        while(n!=0)
        {
           // d=n%10;
            count++;
            n=n>>1;
        }
        int res = pow(2,count)-m-1;
        return res;
    }
};

// Rev 
// https://leetcode.com/problems/complement-of-base-10-integer/