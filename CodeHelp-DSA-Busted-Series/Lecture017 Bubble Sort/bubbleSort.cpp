#include<bits/stdc++.h>
using namespace std;

void bubbleSort(vector<int>& arr, int n)
{   
    for(int i=1; i<n; i++)
    {
        for(int j=0; j<n-i; j++)
        {
            if(arr[j] > arr[j+1])
            {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

// bubble sort optimized
void bubbleSort(vector<int>& arr, int n)
{   
    bool flag;
    for(int i=1; i<n; i++)
    {
        flag = false;
        for(int j=0; j<n-i; j++)
        {
            if(arr[j] > arr[j+1])
            {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
                flag = true;
            }
        }
        if(flag == false)
            {
                // no changes needed
                break;
            }
    }
}

// Revised
//https://www.codingninjas.com/codestudio/problems/bubble-sort_980524?source=youtube&campaign=love_babbar_codestudio2&utm_source=youtube&utm_medium=affiliate&utm_campaign=love_babbar_codestudio2&leftPanelTab=0