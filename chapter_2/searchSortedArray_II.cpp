

// method 1:

class Solution {
public:
    bool search(int A[], int n, int target) {
        int start = 0;
        int end = n - 1;
        int mid;
        
        while(start + 1 < end) {
            mid = start + (end - start) / 2;
            if(A[mid] == target) {
                return true;
            }
            if(A[mid] < A[start]) {
                if(A[mid] <= target && target <= A[end]) {
                    start = mid;
                } else {
                    end = mid;
                }
            } else if(A[mid] > A[start]) {
                if(A[start] <= target && target <= A[mid]) {
                    end = mid;
                } else {
                    start = mid;
                }
            } else if(A[mid] == A[start]) {
                start++; // skip concontinue   // will be wrong if using end--
            }
        } // while
        
        if(A[start] == target) {
            return true;
        }
        if(A[end] == target) {
            return true;
        }
        
        return false;
    }
};

// method 2:

class Solution {
public:
    bool search(int A[], int n, int target) {
        int start = 0;
        int end = n - 1;
        int mid;
        
        while(start + 1 < end) {
            mid = start + (end - start) / 2;
            if(A[mid] == target) {
                return true;
            }
            if(A[mid] > A[end]) {
                if(A[start] <= target && target <= A[mid]) {
                    end = mid;
                } else {
                    start = mid;
                }
            } else if(A[mid] < A[end]) {
                if(A[mid] <= target && target <= A[end]) {
                    start = mid;
                } else {
                    end = mid;
                }
            } else if(A[mid] == A[end]) {
                end--; // will be wrong if using start++
            }
        } // while
        
        if(A[start] == target) {
            return true;
        }
        if(A[end] == target) {
            return true;
        }
        
        return false;
    }
};
