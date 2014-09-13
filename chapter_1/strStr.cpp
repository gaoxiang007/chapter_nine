// https://oj.leetcode.com/problems/implement-strstr/

// this is a nice problem;

class Solution {
public:
    char *strStr(char *haystack, char *needle) {
        if(!*needle) {
            return haystack;
        }
        
        int haystack_len = strlen(haystack);
        int needle_len = strlen(needle);
        
        int i,j;
        for(i=0; i<haystack_len-needle_len+1; ++i) {
            for(j=0; j<needle_len; ++j) {
                if(haystack[i+j] != needle[j]) {
                    break;
                }
            }
            if(j == needle_len) {
                return haystack+i;
            }
        }
        
        return NULL;
    }
};
