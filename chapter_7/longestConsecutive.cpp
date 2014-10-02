
class Solution {
public:
    int longestConsecutive(vector<int> &num) {
        unordered_map<int, int> map;
        for(int i = 0; i < num.size(); ++i) {
            map[num[i]] = 0;
        }
        
        
        int res = INT_MIN;
        
        for(int i = 0; i < num.size(); ++i) {
            int cur = num[i];
            if(map[cur]) {
                continue;
            }
            int max_len = 1;    
            for(int j = cur + 1; map.find(j) != map.end(); ++j) {
                map[j] = 1;
                max_len++;
            }
            for(int k = cur - 1; map.find(k) != map.end(); --k) {
                map[k] = 1;
                max_len++;
            }
            
            res = std::max(res, max_len);

        }
        
        return res;
    }
};
