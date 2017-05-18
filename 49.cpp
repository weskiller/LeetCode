//https://leetcode.com/problems/anagrams
class Solution {
private:
	bool ismatch(const string & a, const string & b) {
		int size = a.size();
		vector<int> count(26, 0);
		for (int i = 0; i < size; i++) {
			count[a[i] - 'a']++;
		}
		for (int i = 0; i < size; i++) {
			count[b[i] - 'a']--;
		}
		for (int i = 0; i < 26; i++) {
			if (count[i] == 0)
				continue;
			else
				return false;
		}
		return true;
	}
public:
	vector<vector<string>> groupAnagrams(vector<string>& strs) {
		vector<vector<string>> result;
		map<int, int> count;
		multimap<int, string> m;
		for (int i = 0; i < strs.size(); i++) {
			m.insert(make_pair(strs[i].size(), strs[i]));
			count[strs[i].size()]++;
		}
		int index = 0;
		for (auto p : count) {
			int size = p.first;
			auto begin = m.lower_bound(size), end = m.upper_bound(size);
			for (auto point = begin; point != end; point++) {
				if (point == begin) {
					result.push_back(vector<string>{string{ begin->second }});
					index = result.size() - 1;
				}
				else {
					bool match = false;
					for (int j = index; j < result.size(); j++) {
						if (ismatch(result[j][0], point->second)) {
							result[j].push_back(point->second);
							match = true;
							break;
						}
					}
					if (!match)
						result.push_back(vector<string>{string{ point->second }});
				}
			}
		}
		return result;
	}
};