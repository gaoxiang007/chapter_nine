// https://oj.leetcode.com/problems/subsets-ii/

class Solution {
public:
    vector<vector<int> > subsetsWithDup(vector<int> &S) {
        vector<vector<int> > res;
        vector<int> path;
        vector<int> visited;
        sort(S.begin(), S.end());
        subsetsHelper(res, path, S, 0, visited);
        return res;
    }
    
private:
    void subsetsHelper(vector<vector<int> >& res, vector<int>& path, const vector<int>& S, int pos, vector<int>& visited) {
        res.push_back(path);
        
        for(int i = pos; i < S.size(); ++i) {
            if(i != pos && S[i] == S[i-1]) {
                continue;
            }
            visited[i] = 1;
            path.push_back(S[i]);
            subsetsHelper(res, path, S, i+1);
            path.pop_back();
            visited[i] = 0;
        }
    }
};
