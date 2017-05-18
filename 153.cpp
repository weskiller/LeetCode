//Subject: https://leetcode.com/problems/find-minimum-in-rotated-sorted-array
class Solution {
public:
	int findMin(vector<int>& nums)
	{
		if (nums.size() <= 2)
			return nums.size() == 2 ? (nums[0] > nums[1] ? nums[1] : nums[0]) : nums[0];
		int size = nums.size(), half = nums.size() / 2;
		vector<int> front(nums.begin(), nums.begin() + half + 1), end(nums.begin() + half, nums.end());

		if (nums[0] > nums[size - 1])
			if (nums[0] > nums[half - 1])
				return findMin(front);
			else
				return findMin(end);
		else
			if (nums[0] > nums[half - 1])
				return findMin(end);
			else
				return findMin(front);
	}
};
//Optimal solution (default sort by Asc)
int findMin(vector<int> &num)
{
	int start = 0, end = num.size() - 1;

	while (start < end) {
		if (num[start] < num[end])
			return num[start];

		int mid = (start + end) / 2;

		if (num[mid] >= num[start]) {
			start = mid + 1;
		}
		else {
			end = mid;
		}
	}

	return num[start];
}