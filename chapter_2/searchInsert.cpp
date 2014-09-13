//https://oj.leetcode.com/problems/search-insert-position/
class Solution {
public:
    int searchInsert(int A[], int n, int target) {
        if(n == 0 || target < A[0]) {
            return 0;
        }
        if(target > A[n-1]) {
            return n;
        }
        
        int start = 0;
        int end = n - 1;
        int mid;
        
        while(start+1 < end) {
            mid = start + (end-start) / 2;
            if(A[mid] == target) {
                return mid;
            }
            else if(A[mid] < target) {
                start = mid;
            }
            else if(A[mid] > target) {
                end = mid;
            }
        }
        
        if(A[start] >= target) {
            return start;
        }
        else if(A[end] <= target) {
            return end;
        }
        else {
            return start+1;
        }
        
    }
};
