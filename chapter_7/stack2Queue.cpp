
//
//  main.cpp
//  stack2Queue
//
//  Created by Peter Liu on 9/29/14.
//  Copyright (c) 2014 Peter Liu. All rights reserved.
//

#include <iostream>
#include <stack>
using namespace std;

// implement a queue using two stacks
class MyQueue {
    
 public:
    MyQueue();
    ~MyQueue();
    void enqueue(int x);
    void dequeue();
    int top();
    
    
 private:
    void stack1toStack2();
    stack<int> s1;
    stack<int> s2;
};


MyQueue::MyQueue() {

}

MyQueue::~MyQueue() {

}

void MyQueue::stack1toStack2() {
    while(!s1.empty()) {
        s2.push(s1.top());
        s1.pop();
    }
}

void MyQueue::enqueue(int x) {
    s1.push(x);
}

void MyQueue::dequeue() {
    if(s2.empty()) {
        stack1toStack2();
    }
    s2.pop();
}

int MyQueue::top() {
    if(s2.empty()) {
        stack1toStack2();
    }
    return s2.top();
}

int main(int argc, const char * argv[])
{

    MyQueue q;
    q.enqueue(5);
    q.enqueue(4);
    q.enqueue(1);
    cout << q.top() << endl;
    q.dequeue();
    cout << q.top() << endl;
    q.enqueue(6);
    cout << q.top() << endl;
    q.dequeue();
    q.dequeue();
    cout << q.top() << endl;
    return 0;
}


