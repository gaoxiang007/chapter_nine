// method 0 : 允许使用额外空间

class Solution {
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
        int n = numbers.size();
        unordered_map<int,int> idx_map;
        for(int i = 0; i < n; ++i) {
            idx_map[numbers[i]] = i;
        }
        vector<int> result;
        for(int i = 0; i < n; ++i) {
            int remain = target - numbers[i];
            if(idx_map.find(remain) != idx_map.end()) {
                int idx1 = i + 1;
                int idx2 = idx_map.find(remain)->second + 1;
                if(idx1 == idx2) {
                    continue;
                }
                result.push_back(idx1);
                result.push_back(idx2);
                break;
            }
        }
        sort(result.begin(), result.end());
        return result;
    }
};


// method 1: 不允许使用额外空间

// 先sort，然后再用two pointer法，但是因为这里要返回index本身，所以这种方法不适用
