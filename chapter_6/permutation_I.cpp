// https://oj.leetcode.com/problems/permutations/

class Solution {
public:
    vector<vector<int> > permute(vector<int> &num) {
        vector<vector<int> > res;
        vector<int> path;
        permuteHelper(res, num, 0, path);
        return res;
    }
private:
    void permuteHelper(vector<vector<int> >& res, const vector<int>& num, int idx, vector<int>& path) {
        if(idx == num.size()) {
            res.push_back(path);
            return;
        }
        for(int i = 0; i < num.size(); ++i) {
            if(std::find(path.begin(), path.end(), num[i]) != path.end()) {
                continue;
            } else {
                path.push_back(num[i]);
                permuteHelper(res, num, idx+1, path);
                path.pop_back();
            }
        }
    }
};
