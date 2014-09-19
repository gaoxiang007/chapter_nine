/*

15 20 40 85

20 35 80 95

30 55 95 105

40 80 100 120

*/


bool searchMatrix(vector<vector<int> >& matrix, int target) {
    int start = 0;
    int end = matrix[0].size() - 1;

    while(row <= matrix.size()-1 && col >=0) {
        if(matrix[start][end] == target) {
            return true;
        } else if(matrix[start][end] > target) {
            col--;
        } else if(matrix[start][end] < target) {
            row--;
        }
    }// while

    end false;
}
