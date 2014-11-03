// Apple interview question. Also , facebook...

//
//  main.cpp
//  kNearestPoints
//
//  Created by Peter Liu on 11/3/14.
//  Copyright (c) 2014 Peter Liu. All rights reserved.
//

#include <iostream>
#include <queue>
#include <vector>
using namespace std;


struct Point {
    int x;
    int y;
    Point(int a, int b): x(a), y(b) {}
};

double distance(const Point& p) {
    return p.x * p.x + p.y * p.y;
}

struct mycomp {
    bool operator() (const Point& a, const Point& b) const {
        return distance(a) < distance(b);
    }
};

vector<Point> findNearest(vector<Point>& points, int k) {
    vector<Point> res;
    if(points.size() == 0) {
        return res;
    }
    priority_queue<Point, vector<Point>, mycomp> max_heap;
    auto p = points.begin();
    while (max_heap.size() < k && p != points.end()) {
        max_heap.push(Point(p->x, p->y));
        ++p;
    }
    
    while(p != points.end()) {
        Point tmp = max_heap.top();
        if(distance(tmp) > distance(*p)) {
            max_heap.pop();
            max_heap.push(Point(p->x, p->y));
        }
        ++p;
    }
    
    while(!max_heap.empty()) {
        Point p = max_heap.top();
        max_heap.pop();
        res.push_back(p);
    }
    
    return res;
}


int main(int argc, const char * argv[])
{

    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}


