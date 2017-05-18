//https://leetcode.com/problems/relative-ranks
class Solution {
public:
	vector<string> findRelativeRanks(vector<int>& nums) {
		vector<string> result(nums.size());
		vector<int> rank;
		for (int i = 0; i < nums.size(); i++) rank.push_back(i);
		sort(rank.begin(), rank.end(), [nums](int a, int b) -> bool {return nums[a] > nums[b]; });
		for (int i = 0; i < nums.size(); i++) {
			result[rank[i]] = to_string(i + 1);
		}
		if (nums.size() > 0)
			result[rank[0]] = "Gold Medal";
		if (nums.size() > 1)
			result[rank[1]] = "Silver Medal";
		if (nums.size() > 2)
			result[rank[2]] = "Bronze Medal";
		return result;
	}
};
