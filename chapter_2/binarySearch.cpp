
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
        
        while(start + 1 < end) {
            mid = start + (end - start) / 2;
            if(array[mid] == target) {
	        end = mid;
	    } else if(array[mid] < target) {
                start = mid;
            } else if(array[mid] > target) {
                end = mid;
            }
        } // while
 
        // when exit while loop, the remaining array has only two elements.
        // the reason why we do array[start] == target first is because we want to output the first occurance of the index;
        // in other words, if we want to find the last occurance, then we need to move array[end] == target first.
        if(array[start] == target) {
            return start;
        }
        if(array[end] == target) {
            return end;
        }
        return -1;

    }
};


