// https://oj.leetcode.com/problems/unique-paths-ii/

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        if(m == 0 && n == 0) {
            return 0;
        }
        
        vector<vector<int> > f(m, vector<int>(n, 0));
        
        
        for(int i = 0; i < m; ++i) {
            if(obstacleGrid[i][0] == 0) {
                f[i][0] = 1;
            } else if(obstacleGrid[i][0] == 1) {
                break;
            }
        }
        
        for(int j = 0; j < n; ++j) {
            if(obstacleGrid[0][j] == 0) {
                f[0][j] = 1;
            } else if (obstacleGrid[0][j] == 1) {
                break;
            }
        }
        
        for(int i = 1; i < m; ++i) {
            for(int j = 1; j < n; ++j) {
                if(obstacleGrid[i][j] == 1) { // (i,j) -> obstacle
                    f[i][j] = 0;
                } else if(obstacleGrid[i][j] == 0) {
                    f[i][j] = f[i-1][j] + f[i][j-1];
                }
            }
        }
        
        return f[m-1][n-1];
    }
};
