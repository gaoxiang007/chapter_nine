// https://oj.leetcode.com/problems/largest-rectangle-in-histogram/

class Solution {
public:
    int largestRectangleArea(vector<int> &height) {
        stack<int> s;
        int max_area = 0;
        height.push_back(0);
        
        for(int i = 0; i < height.size(); ) {
            if(s.empty()) {
                s.push(i++);
            } else {
                if(height[i] >= height[s.top()]) {
                    s.push(i++);
                } else {
                    int tmp = s.top();
                    s.pop();
                    int h = height[tmp];
                    int w = s.empty() ? i : i - s.top() - 1;
                    max_area = std::max(max_area, h * w);
                    //s.push(i);
                } 
                
            }    
            
        }
        
        return max_area;
    }
};
