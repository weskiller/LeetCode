//https://leetcode.com/problems/minimum-moves-to-equal-array-elements-ii
class Solution {
public:
	int minMoves2(vector<int>& nums) {
		int result = 0;
		int avg = 0;
		sort(nums.begin(), nums.end());
		int max = nums.size();
		int i = 0, count = 0, times = 0;
		for (; i < nums.size() && 2 * count <= nums.size();) {
			int j = i;
			while (nums[j] == nums[i]) j++;
			count += j - i;
			if (2 * count == nums.size()) {
				times = j - i;
			}
			i = j;
		}
		avg = nums[i - 1];
		if (times != 0 && times > i - nums.size() / 2) {
			avg = nums[nums.size() / 2 - 1];
		}
		cout << "avg: " << avg << endl;
		for (i = 0; i < nums.size(); i++) {
			int t = avg - nums[i];
			result += t > 0 ? t : -t;
		}
		return result;
	}
};
