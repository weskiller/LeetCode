//https://leetcode.com/problems/find-the-difference
class Solution {
public:
	char findTheDifference(string s, string t) {
		int i = 0, c = 0;
		for (; i < s.size(); i++) {
			c ^= s[i] ^ t[i];
		}
		c ^= t[i];
		return c;
	}
};