// https://oj.leetcode.com/problems/subsets/

class Solution {
public:
    vector<vector<int> > subsets(vector<int> &S) {
        vector<vector<int> > res;
        vector<int> path;
        sort(S.begin(), S.end());
        subsetsHelper(res, path, S, 0);
        return res;
    }
private:
    void subsetsHelper(vector<vector<int> >& res, vector<int>& path, const vector<int>& S, int pos) {
        res.push_back(path);
        for(int i = pos; i < S.size(); ++i) {
            path.push_back(S[i]);
            subsetsHelper(res, path, S, i+1);
            path.pop_back();
        }
    }
};
