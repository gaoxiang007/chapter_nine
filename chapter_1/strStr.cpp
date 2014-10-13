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

// version 2 -  10/09/2014

class Solution {
public:
    char *strStr(char *haystack, char *needle) {
        if(haystack == NULL || needle == NULL) {
            return NULL;
        }
        int m = strlen(haystack);
        int n = strlen(needle);
        int i, j;
        for(i = 0; i < m - n + 1; ++i) {
            for(j = 0; j < n; ++j) {
                if(needle[j] != haystack[i+j]) {
                    break;
                } else {
                    continue;
                }
            }
            if(j == n) {
                return &haystack[i];
            }
        }
        
        return NULL;
    }
};
