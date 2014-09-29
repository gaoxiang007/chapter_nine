// http://blog.csdn.net/worldwindjp/article/details/19938131

/*
题意解析：给你一串数字，解码成英文字母。
类似爬楼梯问题，但要加很多限制条件。
定义数组number，number[i]意味着：字符串s[0..i-1]可以有number[i]种解码方法。
回想爬楼梯问题一样，number[i] = number[i-1] + number[i-2]
但不同的是本题有多种限制：
第一： s[i-1]不能是0，如果s[i-1]是0的话，number[i]就只能等于number[i-2]
第二，s[i-2,i-1]中的第一个字符不能是0，而且Integer.parseInt(s.substring(i-2,i))获得的整数必须在0到26之间。

1010，生成的number数组为：[1,1,1,1,1]
10000，生成的number数组为：[1,1,1,0,0,0,0,0,0]
*/

class Solution {
public:
    int numDecodings(string s) {
        if(s.size() == 0) {
            return 0;
        }
        if(s[0] == '0') {
            return 0;
        }
        
        int f[s.size()+1];
        f[0] = 1;
        f[1] = 1;
        fill_n(f+2, s.size()-1, 0);
        for(int i = 2; i <= s.size(); ++i) {
            if(s[i-1] != '0') {
                f[i] = f[i-1];
            } 
            int two_digits = (s[i-2] - '0') * 10 + (s[i-1] - '0');
            if(two_digits >= 10 && two_digits <= 26) {
                f[i] += f[i-2];
            }
        }
      
        
        return f[s.size()];
    }
};
