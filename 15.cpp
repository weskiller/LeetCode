//https://leetcode.com/problems/3sum
class Solution {
private:
    static const int sum = 0;
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        sort(nums.begin(),nums.end());
        for (int i = 0;i < nums.size() && nums[i] <= sum;i++) {
            if (i > 0 && nums[i] == nums[i-1]) continue;
            int tsum = sum  - nums[i];
            int j  = i + 1, k = nums.size() - 1;
            while (k > j) {
                if (nums[k] + nums[j] > tsum)
                    k--;
                else if (nums[k] + nums[j] < tsum)
                    j++;
                else {
                    result.push_back(vector<int>{nums[i],nums[j],nums[k]});
                    do {
                        j++;
                    }  while (nums[j] == nums[j - 1]);
                    do {
                        k--;
                    }while (nums[k] == nums[k + 1]);
                }
            }
        }
        return result;
    }
};