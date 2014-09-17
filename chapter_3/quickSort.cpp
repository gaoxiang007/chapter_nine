


int partition(int A[], int start, int end) {
    int mid = start + (end - start) / 2;
    int pivot = A[mid];
    
    while(start <= end) {
        while(A[start] < pivot) {
            start++;
        }
        while(A[end] > pivot) {
            end--;
        }
        if(start <= end) {
            swap(&A[start], &A[end]);
            start++;
            end--;
        }
    }// while
    
    return start;
}

void quickSort(int A[], int start, int end) {
    
    if(start >= end) { // array segment has 1 or 0 elements
        return;
    }
    
    int rightBegin = partition(A,start,end);
    
    quickSort(A, start, rightBegin-1);
    quickSort(A, rightBegin, end);
}


