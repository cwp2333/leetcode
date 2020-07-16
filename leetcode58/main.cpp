#include <iostream>
#include <string>
using  namespace std;
/*
 * author:Mr.Cai
 * num:1
 * 给定一个仅包含大小写字母和空格 ' ' 的字符串 s，返回其最后一个单词的长度。如果字符串从左向右滚动显示，那么最后一个单词就是最后出现的单词。
 * 如果不存在最后一个单词，请返回 0 。
 * 说明：一个单词是指仅由字母组成、不包含任何空格字符的 最大子字符串。
 * */

class Solution {
public:
    int lengthOfLastWord(string s) {
        int n = s.length();
        if(n<1) return 0;
        int j = n-1;
        for(j = n-1;j>=0;j--)
        {
            if(s[j]==' '&& j == n-1)
            {
                n = n - 1;
                continue;
            }else if(s[j] == ' ')
            {
                break;
            }
        }
        return n-j-1;
    }
};
int main() {
    string s = "hello ";
    Solution s1;
    cout<< s1.lengthOfLastWord(s)<<endl;
}
