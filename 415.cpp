//Subject: https://leetcode.com/problems/add-strings
class Solution {
public:
	string addStrings(string num1, string num2)
	{
		string result;
		int prev = 0;
		while (!(num1.empty() && num2.empty()))
		{
			int lnum1 = 0, lnum2 = 0;
			if (!num1.empty())
			{
				lnum1 = num1[num1.size() - 1] - 48;
				num1.pop_back();
			}
			if (!num2.empty())
			{
				lnum2 = num2[num2.size() - 1] - 48;
				num2.pop_back();
			}
			result = to_string((lnum1 + prev + lnum2) % 10) + result;
			lnum1 + prev + lnum2 >= 10 ? prev = 1 : prev = 0;
		}
		if (prev == 1)
			result = to_string(prev) + result;
		return result;
	}
};