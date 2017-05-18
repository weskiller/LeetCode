//https://leetcode.com/problems/search-insert-position
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;
        while (right >= left) {
            int n = (left + right) / 2;
            if (target > nums[n]) 
                left = n + 1;
            else
                right = n - 1;
        }
        return left;
    }
};