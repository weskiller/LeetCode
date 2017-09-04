//https://leetcode.com/problems/valid-perfect-square
class Solution {
public:
    bool isPerfectSquare(int num) {
        int n = num % 10;
        if (n == 2 || n == 3 || n == 7 || n == 8)
            return false;
        int factor = 1;
        while (factor * factor <= num) {
            if (num == factor * factor)
                return true;
            if (factor > 1 && num % (factor * factor) == 0) {
                num /= (factor * factor);
                int n = num % 10;
                if (n == 2 || n == 3 || n == 7 || n == 8)
                    return false;
                factor = 1;
            }
            else {
                factor += 1;
            }
        }
        return false;
    }
};
