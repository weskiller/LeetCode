//Subject: https://leetcode.com/problems/regular-expression-matching/
//with recursive function 
class Solution {
public:
	bool isMatch(string s, string p)
	{
		if (p.empty())
			return s.empty();
		if (p[1] == '*')
			return isMatch(s, p.substr(2)) || !s.empty() && (s[0] == p[0] || p[0] == '.') && isMatch(s.substr(1), p);
		else
			return !s.empty() && (s[0] == p[0] || p[0] == '.') && isMatch(s.substr(1), p.substr(1));
	}
};

//with dynamic planning solution
class Solution {
public:
	bool isMatch(string s, string p)
	{
		int t = s.size(), l = p.size();
		std::vector<vector<bool>> w(t + 1, vector<bool>(l + 1, false));

		w[0][0] = true;

		for (int i = 1; i <= t; i++)
			w[i][0] = false;
		for (int i = 1; i <= l; i++)
			w[0][i] = i > 1 && (p[i - 1] == '*' && w[0][i - 2]);


		for (int x = 1; x <= t; x++)
		{
			for (int y = 1; y <= l; y++)
			{
				if (p[y - 1] == '*')
					w[x][y] = w[x][y - 2] || ((s[x - 1] == p[y - 2] || p[y - 2] == '.') && w[x - 1][y]);
				else
					w[x][y] = w[x - 1][y - 1] && (s[x - 1] == p[y - 1] || p[y - 1] == '.');
			}
		}
		return w[t][l];
	}
};