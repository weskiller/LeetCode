//https://leetcode.com/problems/longest-substring-with-at-least-k-repeating-characters
class Solution {
public:
	int longestSubstring(string s, int k) {
		unordered_map<int, int> map;
		for (int i = 0; i < s.size(); i++) {
			map[s[i]]++;
		}
		vector<int> v;
		v.push_back(-1);
		for (int i = 0; i < s.size(); i++) {
			if (map[s[i]] < k)
				v.push_back(i);
		}
		if (v.size() == 1)
			return s.size();
		v.push_back(s.size());
		int max = 0;
		for (int i = 0; i < v.size() - 1; i++) {
			int smax = longestSubstring(s.substr(v[i] + 1, v[i + 1] - v[i] - 1), k);
			if (smax > max)
				max = smax;
		}
		return max;
	}
};
//the jave nice idea soluation
public class Solution {
	public int longestSubstring(String s, int k) {
		char[] str = s.toCharArray();
		int[] counts = new int[26];
		int h, i, j, idx, max = 0, unique, noLessThanK;

		for (h = 1; h <= 26; h++) {
			Arrays.fill(counts, 0);
			i = 0;
			j = 0;
			unique = 0;
			noLessThanK = 0;
			while (j < str.length) {
				if (unique <= h) {
					idx = str[j] - 'a';
					if (counts[idx] == 0)
						unique++;
					counts[idx]++;
					if (counts[idx] == k)
						noLessThanK++;
					j++;
				}
				else {
					idx = str[i] - 'a';
					if (counts[idx] == k)
						noLessThanK--;
					counts[idx]--;
					if (counts[idx] == 0)
						unique--;
					i++;
				}
				if (unique == h && unique == noLessThanK)
					max = Math.max(j - i, max);
			}
		}

		return max;
	}
}
