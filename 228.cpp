//https://leetcode.com/problems/summary-ranges
class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> ret;
        stringstream t;
        int i = 0;
        for(int i = 0; i < nums.size();i++) {
            t << nums[i];
            int j = i + 1;
            for(;j < nums.size();j++)
                if (nums[j] - nums[j - 1] != 1) break;
            j--;
            if (j == i){
                ret.push_back(t.str());
                t.str("");
            }
            else {
                t << "->" << nums[j];
                ret.push_back(t.str());
                t.str("");
                i = j;
            }
        }
        return ret;
    }
};