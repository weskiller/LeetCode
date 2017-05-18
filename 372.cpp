//Subject: https://leetcode.com/problems/super-pow/
class Solution {
public:
    static const int Mod = 1337;
    int PowerMod(int a, int b)
    {
        int result = 1 % Mod;
        for(int i = 0;i < b;i++)
        {
            result = (result * (a % Mod)) % Mod;
        }
        return result;
    }
    int superPow(int a, vector<int>& b) 
    {
        if (b.empty())
            return 1;
        int last = b.back();
        b.pop_back();
        return PowerMod(superPow(a,b),10) * PowerMod(a,last) % Mod;
    }
};