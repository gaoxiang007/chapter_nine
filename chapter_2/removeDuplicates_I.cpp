class Solution {
public:
    int removeDuplicates(int A[], int n) {
        // edge case
        if(n == 0 || n == 1) {
            return n;
        }
        
        int tail = 0;
        int next = 1;
        
        while(next < n) {
            if(A[tail] != A[next]) {
                A[++tail] = A[next];
            }
            next++;
        }
        
        return tail+1;
    }
};
