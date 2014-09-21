

class Solution {
public:
    double findMedianSortedArrays(int A[], int m, int B[], int n) {
        int total = m + n;
        
        if(total %2 == 0) { // even 
            return ( find_kth(A, m, B, n, total/2) + find_kth(A, m, B, n, total/2 + 1) ) / 2.0;
        } else {
            return find_kth(A, m, B, n, total/2 + 1);
        }
    }
    
    // find the kth number in the union of sorted array A and B
    int find_kth(int A[], int m, int B[], int n, int k) { 
        
    }
};
