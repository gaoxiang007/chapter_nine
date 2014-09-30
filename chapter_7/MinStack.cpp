

//
//  main.cpp
//  minStack
//
//  Created by Peter Liu on 9/28/14.
//  Copyright (c) 2014 Peter Liu. All rights reserved.
//

#include <iostream>
#include <stack>
using namespace std;


class MinStack {

public:
    MinStack();
    ~MinStack();
    void push(int x);
    void pop();
    int min();
    int top();
    
private:
    stack<int> s1, s2;
};



MinStack::MinStack() {
    
}

MinStack::~MinStack(){
    while(!s1.empty()) {
        s1.pop();
    }
    while(!s2.empty()) {
        s2.pop();
    }
}

void MinStack::push(int x) {
    s1.push(x);
    if(s2.empty()) {
        s2.push(x);
    } else {
        int tmp = s2.top();
        if(x <= tmp) {
            s2.push(x);
        } else {
            s2.push(tmp);
        }
    }
}

void MinStack::pop() {
    if(!s1.empty()) {
        s1.pop();
    }
    if(!s2.empty()) {
        s2.pop();
    }
}

int MinStack::min(){
    if(!s2.empty()) {
        return s2.top();
    } else {
        return 0;
    }
}

int MinStack::top() {
    return s1.top();
}


int main(int argc, const char * argv[])
{
    MinStack min_stack1;
    min_stack1.push(5);
    min_stack1.push(3);
    min_stack1.push(6);
    min_stack1.push(1);
    min_stack1.pop();
    min_stack1.pop();
    min_stack1.pop();
    min_stack1.pop();
    cout << min_stack1.min() << endl;
    
    return 0;
}


