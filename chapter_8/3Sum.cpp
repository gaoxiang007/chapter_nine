class Solution {
public:
    vector<vector<int> > threeSum(vector<int> &num) {
        vector<vector<int> > result;
        if(num.size() < 3) {
            return result;
        }
        vector<int> path;
        sort(num.begin(), num.end());
        for(int i = 0; i < num.size()-2; ++i) {
            while(i != 0 && num[i] == num[i-1]) {
                ++i;
            }
            int start = i + 1;
            int end = num.size() - 1;
            while(start < end) {
                int sum = num[start] + num[end];
                if(sum + num[i] == 0) {
                    path.push_back(num[i]);
                    path.push_back(num[start]);
                    path.push_back(num[end]);
                    result.push_back(path);
                    path.clear();
                    ++start;
                    --end;
                    while(start < end && num[start] == num[start-1]) {
                        start++;
                    }
                    while(start < end && num[end] == num[end+1]) {
                        end--;
                    }
                }else if(sum + num[i] < 0) {
                    start++;
                } else {
                    end--;
                }
            }//while
            
        }//for
        
        return result;
    }
};
