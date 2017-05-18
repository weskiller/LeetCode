//https://leetcode.com/problems/evaluate-reverse-polish-notation
class Solution {
public:
	int evalRPN(vector<string>& tokens) {
		stack<int> s;
		for (string & str : tokens) {
			if (str != "+" && str != "-" && str != "*" && str != "/") {
				s.push(strtod(str.c_str(), NULL));
			}
			else if (str == "+") {
				int a = s.top();
				s.pop();
				int b = a + s.top();
				s.pop();
				s.push(b);
			}
			else if (str == "-") {
				int b = s.top();
				s.pop();
				int a = s.top();
				s.pop();
				s.push(a - b);
			}
			else if (str == "*") {
				int a = s.top();
				s.pop();
				int b = a * s.top();
				s.pop();
				s.push(b);
			}
			else if (str == "/") {
				int b = s.top();
				s.pop();
				int a = s.top();
				s.pop();
				s.push(a / b);
			}
		}
		return s.top();
	}
};