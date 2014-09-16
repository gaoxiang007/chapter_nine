// mergeSort


// arr = {1,3,-1,9,5}  -> {-1,1,3,5,9}


void merge(int arr[], int start, int mid, int end) {
    int size = end - start + 1;
    int* new_array = new int[sizes];

    for(int i=start; i<end; ++i) {
        new_array[i] = arr[i]; // TO DO
    }
}

void mergeSortHelper(int arr[], int start, int end) {
    if(start > end) { // if equal sign necessary
        return;
    }
    int mid = start + (end-start)/2;
    mergeSortHelper(arr,0,mid);
    mergeSortHelper(arr,mid+1,end);

    // merge is doing the heavy lifting
    merge(arr,start,mid,end);
    
}

void mergeSort(int arr[]) {
    int size = sizeof(arr)/sizeof(arr[0]);
    mergeSortHelper(arr,0,size-1);
}
