// https://oj.leetcode.com/problems/permutations-ii/

class Solution {
public:
    vector<vector<int> > permuteUnique(vector<int> &num) {
        vector<vector<int> > res;
        vector<int> path;
        vector<int> visited(num.size(), 0);
        sort(num.begin(), num.end());
        permuteHelper(res, num, 0, path, visited);
        return res;
    }
private:
    void permuteHelper(vector<vector<int> >& res, const vector<int>& num, int idx, vector<int>& path, vector<int>& visited) {
        if(idx == num.size()) {
            res.push_back(path);
            return;
        }
        for(int i = 0; i < num.size(); ++i) {
            if(visited[i] == 1 || (i!=0 && num[i] == num[i-1] && visited[i-1] == 0 )) {
                continue;
            } else {
                visited[i] = 1;
                path.push_back(num[i]);
                permuteHelper(res, num, idx+1, path, visited);
                path.pop_back();
                visited[i] = 0;
            }
        }
    }
};
