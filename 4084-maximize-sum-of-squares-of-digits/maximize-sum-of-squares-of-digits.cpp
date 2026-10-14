
class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        if (sum > num * 9) return "";

        string res;
        while (num--) {
            if (sum >= 9) {
                res += '9';
                sum -= 9;
            } else if (sum == 0) {
                res += '0';
            } else {
                res += to_string(sum);
                sum = 0;
            }
        }
        return res;
    }
};