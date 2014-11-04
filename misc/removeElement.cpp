int removeElement(int A[], int n, int elem) {
    int i = 0, j = 0;
    for(; j < n; ++j) {
        if(A[j] != elem) {
            A[i++] = A[j];
        }   
    }
    return i;
}
