//Subject: https://leetcode.com/problems/excel-sheet-column-number
class Solution {
public:
    int titleToNumber(string s) 
    {
        int cout = 0;
        for(int i = 0; i < s.size(); i++)
        {
            cout += (s[i] - 64) * pow(26,(s.size() - 1 - i));
        }
        return cout;
    }
};