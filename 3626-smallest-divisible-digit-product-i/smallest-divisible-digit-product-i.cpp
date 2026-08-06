class Solution {
public:
    int smallestNumber(int n, int t) {
        long long int ans;
        
        for (int i = n; ; i++) {
            int prdt = 1;
            int original = i;
            int temp = i;

            while (temp) {
                int digit = temp % 10;
                prdt *= digit;
                temp /= 10;
            }

            if (prdt % t == 0) {
                ans = original;
                break;
            }
        }

        return ans;
    }
};