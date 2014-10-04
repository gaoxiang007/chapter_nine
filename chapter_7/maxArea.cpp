// https://oj.leetcode.com/problems/container-with-most-water/
/*
这两题看起来有点像，但是实际上是完全不一样的，区别在于：
The "Container With Most Water" solution will allow the water to rise above intermediate positions. With the "largest rectangle" problem, the rectangle cannot rise above intermediate bars.
也就是说Container With Most Water只考虑左右边界，[i,j]范围内的Area = min(height[i],height[j]) * (j-i);而Largest Rectangle in Histogram，高度最小值为[i,j]范围内所有高度的最小值。后者比前者要难很多
1.Container With Most Water
对于这题，考虑左右边界[i,j] ,当height[i]<height[j]时，因为i是其中的短板，则无论j取[i+1,j]中的任何值，Area都只会比当前已求出的[i,j]的Area小（横坐标范围减小，再遇见比height[i]更小的右边界），因此以i为左边界的情况不再考虑，i++；反之，j--，同样的思考方式。
http://ouqi.iteye.com/blog/1956168
*/



class Solution {
public:
    int maxArea(vector<int> &height) {
        if(height.size() == 0) {
            return 0;
        }
        int max_area = 0;
        int area = 0;
        int start = 0;
        int end = height.size() - 1;
        while (start < end) {
            if(height[start] < height[end]) {
                area = height[start] * (end - start);
                start++;
                
            } else if(height[start] >= height[end]) {
                area = height[end] * (end - start);
                end--;
            }
            max_area = max(max_area, area);
        }
        
        return max_area;
    }
};
