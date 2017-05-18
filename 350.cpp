//Subject: https://leetcode.com/problems/intersection-of-two-arrays-ii/
class Solution {
public:
	vector<int> intersect(vector<int>& nums1, vector<int>& nums2)
	{
		sort(nums1.begin(), nums1.end());
		sort(nums2.begin(), nums2.end());
		vector<int> result;
		int i = 0, j = 0;
		while (i < nums1.size() && j < nums2.size() && !(nums2[j] > nums1[nums1.size() - 1]))
		{
			if (nums1[i] == nums2[j])
			{
				result.push_back(nums1[i]);
				i++;
				j++;
			}
			else if (nums1[i] < nums2[j])
			{
				i++;
			}
			else if (nums1[i] > nums2[j])
			{
				j++;
			}
		}
		return result;
	}
};