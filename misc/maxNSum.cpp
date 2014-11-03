//http://www.mitbbs.com/article_t/JobHunting/32594121.html

//
//  main.cpp
//  maxNSum
//
//  Created by Peter Liu on 11/3/14.
//  Copyright (c) 2014 Peter Liu. All rights reserved.
//

#include <iostream>
#include <vector>
#include <queue>
using namespace std;


struct Node {
    int val;
    int pos;
    Node(int v, int p): val(v), pos(p) {}
};


struct mycomp {
    bool operator() (Node x, Node y) {
        if( x.val < y.val ) {
            return true;
        } else {
            return false;
        }
    }
};

vector<int> maxNSum(vector<int>& A, vector<int>& B, int N) {
    vector<int> result(N,0);
    vector<int> position(N,0);
    priority_queue<Node, vector<Node>, mycomp> heap;
    
    for(int i = 0; i < N; ++i) {
        heap.push(Node(A[i]+B[0], i));
    }
    
    for(int i = 0; i < N; ++i) {
        Node tmp = heap.top();
        heap.pop();
        result[i] = tmp.val;
        int pos = tmp.pos;
        position[pos]++;
        if(position[pos] < N) {
            heap.push(Node(A[pos]+B[position[pos]], pos));
        }
    }
    return result;
}


void prettyPrint(vector<int>& vec) {
    for(int i = 0; i < vec.size(); ++i) {
        cout << vec[i] << " ";
    }
    cout << endl;
}

int main(int argc, const char * argv[])
{
    vector<int> A;
    A.push_back(4);
    A.push_back(3);
    A.push_back(1);
    vector<int> B;
    B.push_back(6);
    B.push_back(5);
    B.push_back(2);
    
    vector<int> res1 = maxNSum(A, B, 3);
    prettyPrint(res1);
    return 0;
}


