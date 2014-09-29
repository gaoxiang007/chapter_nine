// http://www.geeksforgeeks.org/dynamic-programming-set-3-longest-increasing-subsequence/

//
//  main.cpp
//  LIS
//
//  Created by Peter Liu on 9/28/14.
//  Copyright (c) 2014 Peter Liu. All rights reserved.
//

#include <iostream>
using namespace std;



int longestIncreasingSubsequence(int arr[], int n) {

    int L[n];
    for(int i = 0; i <n; ++i) {
        L[i] = 1;
    }

    int res;
    for(int i = 1; i < n; ++i) {
        for(int j = 0; j < i; ++j) {
            if(arr[j] < arr[i]) {
                L[i] = std::max(L[i], 1 + L[j]);
            }
        }
    }

    
    for(int i = 1; i <=n ; ++i) {
        res = max(res,L[i]);
    }
    
    return res;
}

int main(int argc, const char * argv[])
{

    int arr[] = {10, 22, 9, 33, 21, 50, 41, 60, 80 };
    cout << longestIncreasingSubsequence(arr, 9) << endl;
    return 0;
}


