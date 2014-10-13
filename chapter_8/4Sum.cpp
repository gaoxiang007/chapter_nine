class Solution {
public:
    vector<vector<int> > fourSum(vector<int> &num, int target) {
        vector<vector<int> > result;
        if(num.size() < 4) {
            return result;
        }
        sort(num.begin(), num.end());
        for(int i = 0; i < num.size() - 3; ++i) {
            if(i != 0 && num[i] == num[i-1]) {
                continue;
            }
            for(int j = i + 1; j < num.size() - 2; ++j) {
                if(j != i + 1&& num[j] == num[j-1]) {
                    continue;
                }
                
                int left = j + 1;
                int right = num.size() - 1;
                while(left < right) {
                    int sum = num[i] + num[j] + num[left] + num[right];
                    if(sum == target) {
                        vector<int> path;
                        path.push_back(num[i]);
                        path.push_back(num[j]);
                        path.push_back(num[left]);
                        path.push_back(num[right]);
                        result.push_back(path);
                        left++;
                        right--;
                        while(left < right && num[left] == num[left-1]) {
                            left++;
                        }
                        while(left < right && num[right] == num[right+1]) {
                            right--;
                        }
                    } else if(sum < target) {
                        left++;
                    } else {
                        right--;
                    }
                }// while
                
            }
        }
        
        return result;
    }
};
