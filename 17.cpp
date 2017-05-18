//Subject: https://leetcode.com/problems/remove-element/
class Solution {
public:
    int removeElement(vector<int>& nums, int val) 
    {
        int length = nums.size();
        for(int i = 0,j = 0;i < length;i += 1)
        {
            vector<int>::iterator tmp(nums.begin() + (i - j));
            if((i - j ) > nums.size())
                break;
            if (*tmp == val)
            {
                nums.erase(tmp);
                j++;
            }
        }
        return nums.size();
    }
};
//Optimal solution
// 1
public int removeElement(int[] nums, int val) {
    int i = 0;
    for (int j = 0; j < nums.length; j++) {
        if (nums[j] != val) {
            nums[i] = nums[j];
            i++;
        }
    }
    return i;
}
// 2
public int removeElement(int[] nums, int val) {
    int i = 0;
    int n = nums.length;
    while (i < n) {
        if (nums[i] == val) {
            nums[i] = nums[n - 1];
            // reduce array size by one
            n--;
        } else {
            i++;
        }
    }
    return n;
}