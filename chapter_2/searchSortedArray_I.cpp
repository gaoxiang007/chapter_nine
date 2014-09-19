
// method 1:

class Solution {
public:
    int search(int A[], int n, int target) {
        int start = 0;
        int end = n - 1;
        int mid;
        
        while(start + 1 < end) {
            mid = start + (end - start) / 2;
            if(A[mid] == target) {
                return mid;
            }
            if(A[mid] < A[end]) { // right half is normally ordered
                if(A[mid] <= target && target <= A[end]) {
                    start = mid;
                } else {
                    end = mid;
                }
            } else if(A[mid] > A[end]) { // left half is normally ordered
                if(A[start] <=target && target <= A[mid]) {
                    end = mid;
                } else {
                    start = mid;
                }
            }
        } // while
        
        if(A[start] == target) {
            return start;
        }
        if(A[end] == target) {
            return end;
        }
        return -1;
    }
};


// method 2:

class Solution {
public:
    int search(int A[], int n, int target) {
        int start = 0;
        int end = n - 1;
        int mid;
        
        while(start + 1 < end) {
            mid = start + (end - start) / 2;
            if(A[mid] == target) {
                return mid;
            }
            if(A[start] < A[mid]) { // left half is normally ordered half
                if(A[start] <= target && target <= A[mid]) {
                    end = mid;
                } else {
                    start = mid;
                }
            } else if(A[start] > A[mid]) { // right half is normally ordered half
                if(A[mid] <= target && target <= A[end]) {
                    start = mid;
                } else {
                    end = mid;
                }
            } 
        } // while
        
        if(A[start] == target) {
            return start;
        }
        if(A[end] == target) {
            return end;
        }
        return -1;
    }
};
