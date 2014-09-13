
// http://lintcode.com/en/problem/binary-search/


using namespace std;

class Solution {
public:
    /**
     * @param array source array
     * @param target target to search
     * @return the first occurrence position of target 
     */
    int binarySearch(vector<int> &array, int target) {
        // write your code here
        if(array.size() == 0) {
            return -1;
        }
        
        int start = 0;
        int end = array.size()-1;
        int mid = 0;
        
        while(start < end) {
            int mid_idx = (start+end)/2;
            int mid_ele = array(mid_idx);
            if(mid_ele == target) {
                return mid_idx;
            }
            else if(mid_ele < target) {
                start = mid_idx;
            }
            else {
                end = mid_idx;
            }
            
        }
        return -1;
    }
};


