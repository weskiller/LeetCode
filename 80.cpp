//https://leetcode.com/problems/remove-duplicates-from-sorted-array-i
class Solution {
public:
	int removeDuplicates(vector<int>& nums) {
		for (auto i = nums.begin(); i < nums.end();) {
			if (i + 2 < nums.end() && *(i + 2) == *i) {
				int length = i - nums.begin();
				nums.erase(i + 2);
				i = nums.begin() + length;
			}
			else
				i++;
		}
		return nums.size();
	}
};
//
int removeDuplicates(vector<int>& nums) {
	int i = 0;
	for (int n : nums)
		if (i < 2 || n > nums[i - 2])
			nums[i++] = n;
	return i;
}