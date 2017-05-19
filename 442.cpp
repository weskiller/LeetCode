//https://leetcode.com/problems/find-all-duplicates-in-an-array
class Solution {
public:
	vector<int> findDuplicates(vector<int>& nums) {
		vector<int> result;
		vector<int> v(nums.size(), 1);
		for (auto x : nums) {
			v[x - 1] -= 1;
			if (v[x - 1] == -1)
				result.push_back(x);
		}
		return result;
	}
};