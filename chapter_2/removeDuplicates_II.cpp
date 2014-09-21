

class Solution {
public:
    int removeDuplicates(int A[], int n) {
        // edge cases
        if(n == 0 || n == 1) {
            return n;
        }
        
        int tail = 0;
        int count = 1;
        
        int idx = 1;
        while(idx <= n-1) {
            if(A[idx] == A[tail]) {
                if(count < 2) {
                    count++;
                    A[++tail] = A[idx];
                } else {
                    count++;
                }
                
            } else { // A[idx] != A[tail]
                A[++tail] = A[idx];
                count = 1;
            }
            idx++;
        } // while
        
        return tail + 1;
    }
};
