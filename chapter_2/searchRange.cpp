// https://oj.leetcode.com/submissions/detail/11532528/
// Given a sorted array of integers, find the starting and ending position of a given target value.
// http://answer.ninechapter.com/solutions/search-for-a-range/

class Solution {
public:
    vector<int> searchRange(int A[], int n, int target) {
        vector<int> res;
        int first_idx, last_idx;
        
        // find first occurance
        int start = 0;
        int end = n-1;
        int mid;
        while(start + 1 < end) {
            mid = start + (end - start) / 2;
            if(A[mid] == target) {
                end = mid;
            } else if (A[mid] < target) {
                start = mid;
            } else if(A[mid] > target) {
                end = mid;
            }
        }
        
        if(A[start] == target) {
            first_idx = start;
        } else if(A[end] == target){
            first_idx = end;
        } else {
            first_idx = -1;
            last_idx = -1;
            res.push_back(first_idx);
            res.push_back(last_idx);
            return res;
        }
        
        // find last occurance
        start = 0;
        end = n-1;
        while(start + 1 < end) {
            mid = start + (end - start) / 2;
            if(A[mid] == target) {
                start = mid;
            } else if (A[mid] < target) {
                start = mid;
            } else if(A[mid] > target) {
                end = mid;
            }
        }
        
        if(A[end] == target) {
            last_idx = end;
        } else if(A[start] == target) {
            last_idx = start;
        } else {
            first_idx = -1;
            last_idx = -1;
            res.push_back(first_idx);
            res.push_back(last_idx);
            return res;
        }
        
        res.push_back(first_idx);
        res.push_back(last_idx);
        
        return res;
    }
};
