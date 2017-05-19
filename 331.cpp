//https://leetcode.com/problems/verify-preorder-serialization-of-a-binary-tree
class Solution {
public:
	bool isValidSerialization(string preorder) {
		stack<pair<string, int>> S;
		if (preorder.empty())
			return false;
		for (int i = 0; i < preorder.size(); i++) {
			if (preorder[i] == '#') {
				if (S.size() == 0) {
					if (i == 0 && preorder.size() == 1)
						return true;
					else
						return false;
				}
				if (S.size() > 0)
					S.top().second -= 1;
				i++;
			}
			else {
				int start = i;
				while (i < preorder.size() && preorder[i] != ',') i++;
				S.push(pair<string, int>(preorder.substr(start, i - start), 2));
			}
			if (S.size() > 0 && S.top().second == 0) {
				do {
					S.pop();
					if (S.size() > 0)  S.top().second -= 1;
				} while (S.size() > 0 && S.top().second == 0);
				if (S.size() == 0 && i < preorder.size() - 1)
					return false;
			}
		}
		if (S.size() == 0)
			return true;
		else
			return false;
	}
};
