//https://leetcode.com/problems/majority-element-ii
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int> result;
        if (nums.empty())
            return result;
        int max = nums.size() / 3;
        int v1 = nums[0];
        int v2 = nums[1];
        int c1 ,c2;
        c1 = c2 = 0;
        for(int x : nums) {
            if (x == v1)
                c1++;
            else if (x == v2)
                c2++;
            else if (c1 == 0) {
                v1 = x;
                c1 = 1;
            }
            else if (c2 == 0) {
                v2 = x;
                c2 = 1;
            }
            else {
                c1--;
                c2--;
            }
        }
        c1 = c2 = 0;
        for (int x : nums){
            if ( x == v1)
                c1++;
            else if (x == v2)
                c2++;
        }
        if ( c1 > max) result.push_back(v1);
        if ( c2 > max) result.push_back(v2);
        return result;
    }
};