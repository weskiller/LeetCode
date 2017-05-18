class Solution {
public:
	void ReverseDeepFirstSearch(string & str, const string & sstr, int index, int removed_9, int grab_9, int removed_0, int grab_0, int pair, vector<string> & result) {
		static unordered_map<string, int> m;
		if (index == str.size() && pair == 0 && (!m[sstr]) && grab_9 == grab_0) {
			result.push_back(sstr);
			m[sstr]++;
		}
		else if (index > str.size())
			return;
		if (str[index] == '(') {
			if (pair > 0)
				ReverseDeepFirstSearch(str, sstr + "(", index + 1, removed_9, grab_9 + 1, removed_0, grab_0, pair, result);
			if (removed_9 > 0)
				ReverseDeepFirstSearch(str, sstr, index + 1, removed_9 - 1, grab_9, removed_0, grab_0, pair, result); // ignore (
		}
		else if (str[index] == ')') {
			if (pair > 0 && grab_9 > grab_0)
				ReverseDeepFirstSearch(str, sstr + ")", index + 1, removed_9, grab_9, removed_0, grab_0 + 1, pair - 1, result);
			if (removed_0 > 0)
				ReverseDeepFirstSearch(str, sstr, index + 1, removed_9, grab_9, removed_0 - 1, grab_0, pair, result); // ignore )
		}
		else {
			ReverseDeepFirstSearch(str, sstr + str[index], index + 1, removed_9, grab_9, removed_0, grab_0, pair, result);
		}
	}
	vector<string> removeInvalidParentheses(string s) {
		vector<string> result;
		int r9 = 0, r0 = 0, pair = 0;
		for (auto x : s) {
			if (x == '(') r9++;
			if (x == ')') {
				if (r9 > 0) {
					r9--;
					pair++;
				}
				else
					r0++;
			}
		}
		ReverseDeepFirstSearch(s, string{ "" }, 0, r9, 0, r0, 0, pair, result);
		return result;
	}
};