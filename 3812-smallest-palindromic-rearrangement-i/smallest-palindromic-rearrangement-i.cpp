class Solution {
public:
    string smallestPalindrome(string s) {
        int n = s.length();
        int p = n / 2;

        sort(s.begin(), s.begin() + p);

        for (int i = 0; i < p; ++i) {
            s[n - 1 - i] = s[i];
        }
        return s;
    }
};