
// https://oj.leetcode.com/problems/search-a-2d-matrix/
class Solution {
public:
    bool searchMatrix(vector<vector<int> > &matrix, int target) {

        if(target<matrix[0][0]) {
            return false;
        }
        
        int startRow = 0;
        int endRow = matrix.size()-1;
        
        while(startRow <= endRow){
            int mid = startRow + (endRow - startRow) / 2;
            if(matrix[mid][0] == target) {
                return true;
            }
            else if(matrix[mid][0] < target) {
                startRow = mid + 1;
            }
            else {
                endRow = mid - 1;
            }
        } // while
        
        int targetRow = endRow; 
        // edge case: 
        // [[1]], 2 would have run time error if we use targetRow = startRow

        
        int startCol = 0;
        int endCol = matrix[0].size()-1;
        
        while(startCol <= endCol){
            int mid = startCol + (endCol - startCol) / 2;
            if(matrix[targetRow][mid] == target) {
                return true;
            }
            else if(matrix[targetRow][mid] < target) {
                startCol = mid + 1;
            }
            else {
                endCol = mid - 1;
            }
        } //while
        
        return false;
    }
};
