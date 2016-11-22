//Subject: https://leetcode.com/problems/valid-parentheses/
class Solution {
public:
map<char,char>table{{'(',')'},{'[',']'},{'{','}'}};
bool isValid(string s) {
        stack<char> left;
        for(auto c:s){
            if(c=='('||c=='['||c=='{')
                left.push(c);
            else if((!left.empty()) &&table[left.top()]==c)
                left.pop();
            else
                return false;
        }
        if(left.empty())
            return true;
        else
            return false;
    }
};
