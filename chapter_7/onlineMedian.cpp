// refer to EPL page 268
//
//  main.cpp
//  onlineMedian
//
//  Created by Peter Liu on 10/1/14.
//  Copyright (c) 2014 Peter Liu. All rights reserved.
//

#include <iostream>
#include <sstream>
#include <queue>
#include <string>
using namespace std;

// C++ priority_queue的default comp 是 less(最大的元素在top)
void onlineMedian(istringstream* sin) {
    priority_queue<int, vector<int>, greater<int> > right; // Min-heap - stores the bigger part of the stream
    priority_queue<int, vector<int>, less<int> > left; // Max-heap - stores the smaller part of the stream
    
    int x;
    while (*sin >> x) {
        if(!left.empty() && x < right.top()) {
            right.emplace(x);
        } else {
            left.emplace(x);
        }
        
        if(right.size() > left.size() + 1) {
            left.emplace(right.top());
            right.pop();
        } else if(left.size() > right.size() + 1) {
            right.emplace(left.top());
            left.pop();
        }
        
        if (left.size() == right.size()) {
            cout << 0.5 * (left.top() + right.top()) << endl;
        } else {
            cout << (left.size() > right.size() ? left.top() : right.top()) << endl;
        }
    }
    

}

int main(int argc, const char * argv[])
{
    string stringvalues = "3 7 6 10 12";
    istringstream iss(stringvalues);
    
    onlineMedian(&iss);
    
    return 0;
}


