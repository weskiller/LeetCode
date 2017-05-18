//Subject: https://leetcode.com/problems/count-of-smaller-numbers-after-self
class Solution {
public:
	vector<int> countSmaller(vector<int>& nums)
	{
		vector<int> result;
		vector<int> tmp;
		for (auto ptr = nums.rbegin(); ptr != nums.rend(); ptr++)
		{
			int times = 0;
			vector<int>::iterator tmptr = lower_bound(tmp.begin(), tmp.end(), *ptr);
			if (tmptr == tmp.end())
			{
				times = tmp.size();
				tmp.push_back(*ptr);
			}
			else
			{
				times = tmptr - tmp.begin();
				tmp.insert(tmptr, *ptr);
			}
			result.insert(result.begin(), times);
		}
		return result;
	}
};
// Example Binary Indexed Tree(BIT) solution
class Solution {
private:
	vector<int> fenwick;                                // array for fenwick tree

	// get least significant bit
	int lsb(int i) { return i & (-i); }

	// update fenwick tree for adding 1 to ith element in original array
	void addOne(int i) {
		for (i++; i < fenwick.size(); i += lsb(i)) { fenwick[i]++; }
	}

	// get sum for original array's [0, i] elements
	int getSum(int i) {
		int sum = 0;
		for (i++; i > 0; i -= lsb(i)) { sum += fenwick[i]; }
		return sum;
	}

public:
	vector<int> countSmaller(vector<int>& nums) {
		int minNum = INT_MAX, maxNum = INT_MIN, len = nums.size();
		for (int n : nums) { minNum = min(minNum, n), maxNum = max(maxNum, n); }

		fenwick = vector<int>(maxNum - minNum + 2, 0);  // initialize fenwick tree
		vector<int> ans(len);                           // initialize answer array
		for (int i = len - 1; i >= 0; i--) {
			ans[i] = getSum(nums[i] - minNum - 1);      // get sum of number of numbers smaller than nums[k]
			addOne(nums[i] - minNum);                   // update fenwick tree
		}
		return ans;
	}
};