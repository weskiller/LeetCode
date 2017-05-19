//https://leetcode.com/problems/find-all-duplicates-in-an-array
class Solution {
public:
	vector<int> findDuplicates(vector<int>& nums) {
		vector<int> result;
		vector<int> v(nums.size(), 1);
		for (auto x : nums) {
			v[x - 1] -= 1;
		}
		for (int i = 0; i < v.size(); i++) {
			if (v[i] == -1)
				result.push_back(i + 1);
		}
		return result;
	}
};
