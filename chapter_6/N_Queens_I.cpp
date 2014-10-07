// https://oj.leetcode.com/problems/n-queens/

class Solution {
public:

    vector<string> drawChessBoard(const vector<int>& C) {
        vector<string> res;
        int N = C.size(); // square matrix
        for(int i = 0; i < N; ++i) {
            res.push_back(""); // init the ith row
            for(int j = 0; j < N; ++j) {
                if(C[i] == j) {
                    res[i].push_back('Q');
                } else {
                    res[i].push_back('.');
                }
            }
        }
        
        return res;
    }
    
    // isValid的作用是验证 (C.size(), col) 这个点是否可行
    bool isValid(const vector<int>& C, int col) {
       int row = C.size(); 
       for(int i =0; i < row; ++i) {
           // check column
           if(C[i] == col) {
               return false;
           }
           if(row + col == i + C[i]) { // 次对角线上两点的性质，举例验证
               return false;
           }
           if(row - col == i - C[i]) { // 主对角线上两点的性质，举例验证
               return false;
           }
           
       } 
       
       return true;
       
    }

    void dfs(vector<vector<string> >& sol, int n, vector<int>& C) {
        if(C.size() == n) {
            // draw the chessboard
            sol.push_back(drawChessBoard(C));
            return;
        }
        
        for(int col = 0; col < n; ++col) {
            if(!isValid(C, col)) {
                continue;
            }
            C.push_back(col); // go to next row
            dfs(sol, n, C);
            C.pop_back();  // revoke current row
        }
    }
    
    vector<vector<string> > solveNQueens(int n) {
        vector<vector<string> > sol;
        if(n <= 0) {
            return sol;
        }
        vector<int> C; // c[i] = j   -> the Queen on row i is on column j
        dfs(sol, n, C);
    }
};
