//https://leetcode.com/problems/wildcard-matching
#include <iostream>
#include <string>
#include <vector>
using namespace std;
class Solution {
public:
	bool isMatch(string s, string p) {
		if (s.empty()) {
			int x = 0;
			while (x < p.size() && p[x] == '*') x++;
			if (x == p.size())
				return true;
			else
				return false;
		}
		int ssize = s.size(), psize = p.size();
		int[ssize + 1][psize + 1];
		for (int i = 0; i < ssize + 1; i++)
			for (int j = 0; j < psize + 1; j++) {
				t[i][j] = false;
			}
		t[0][0] = true;
		for (int i = 1; i < ssize + 1; i++) {
			int min = 0;
			for (int j = 1; j < psize + 1; j++) {
				if (p[j - 1] == '?') {
					min++;
					if (i >= min && (t[i - 1][j - 1] == true || (j - 1 > 0 && p[j - 2] == '*' && t[i][j - 1] == true))) {
						if (j == psize) {
							if (t[i - 1][j - 1] == true)
								t[i][j] = true;
						}
						else
							t[i][j] = true;
					}
				}
				else if (p[j - 1] == '*') {
					if (t[i - 1][j - 1] == true || t[i][j - 1] == true || (j - 1 == 0 || t[i - 1][j] == true))
						t[i][j] = true;
				}
				else {
					min++;
					if (t[i - 1][j - 1] == true && s[i - 1] == p[j - 1])
						t[i][j] = true;
					else if (j - 1 > 0 && p[j - 2] == '*') {
						int k = j;
						while (k - 1 > 0 && p[k - 2] == '*') k--;
						if (s[i - 1] == p[j - 1] && t[i - 1][k - 1] == true)
							t[i][j] = true;
					}
				}
			}
		}
		return t[ssize][psize];
	}
};
int main(int n, char * arg[]) {
	Solution S;
	if (arg[1] == NULL || arg[2] == NULL)
		return 0;
	string input{ arg[1] };
	string match{ arg[2] };
	cout << "input:\"" << input << "\",match:\"" << match << "\"" << endl;
	bool result;
	result = S.isMatch(input, match);
	if (result)
		cout << "true" << endl;
	else
		cout << "false" << endl;
	return 0;
}
