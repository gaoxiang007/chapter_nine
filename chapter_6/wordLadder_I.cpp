// https://oj.leetcode.com/problems/word-ladder/
// 


// method - 1 : erase 的应用很巧妙，但不general 
class Solution {
public:
    int ladderLength(string start, string end, unordered_set<string> &dict) {
        if(dict.size() == 0) {
            return 0;
        }
        queue<string> queue;
        queue.push(start);
        dict.erase(start);
        int length = 0;
        bool found = false;
        
        while(!queue.empty() && !found) {
            int count = queue.size();
            for(int i = 0; i < count; ++i) {
                string cur = queue.front();
                queue.pop();
                for(char ch = 'a'; ch <= 'z'; ++ch) {
                    for(int j = 0; j < cur.size(); ++j) {
                        if(ch == cur[j]) {
                            continue;
                        }
                        string tmp = cur;
                        tmp[j] = ch;
                        if(tmp == end) {
                            found = true;
                        }
                        if(dict.count(tmp) > 0) {
                            queue.push(tmp);
                            dict.erase(tmp);
                        } else {
                            continue;
                        }
                    }
                }
            }
            length++;
        }// while
        
        if(found) {
            return length + 1;
        } else {
            return 0;
        }
    }
};


// method - 2: 更加general的判重方法

class Solution {
public:
    int ladderLength(string start, string end, unordered_set<string> &dict) {
        if(dict.size() == 0) {
            return 0;
        }
        queue<string> queue;
        queue.push(start);
        unordered_map<string, int> visited;
        for(unordered_set<string>::iterator it = dict.begin(); it != dict.end(); ++it) {
            visited[*it] = 0;
        }
        
        int length = 0;
        bool found = false;
        
        while(!queue.empty() && !found) {
            int count = queue.size();
            for(int i = 0; i < count; ++i) {
                string cur = queue.front();
                queue.pop();
                for(char ch = 'a'; ch <= 'z'; ++ch) {
                    for(int j = 0; j < cur.size(); ++j) {
                        if(ch == cur[j]) {
                            continue;
                        }
                        string new_word = cur;
                        new_word[j] = ch;
                        if(new_word == end) {
                            found = true;
                            break;
                        }
                        if(dict.count(new_word) > 0 && visited[new_word] == 0) {
                            queue.push(new_word);
                            visited[new_word] = 1;
                        } 
                    }
                }
            }
            length++;
        }// while
        
        if(found) {
            return length + 1;
        } else {
            return 0;
        }
    }
};
