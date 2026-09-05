class Solution {
    boolean isPalindrome(int i, int j, String s) {
        while (i < j) {
            if (s.charAt(i) == s.charAt(j)) {
                i++;
                j--;
            } 
            else {
                return false;
            }
        }
        return true;
    }
    public String longestPalindrome(String s) {
        int n = s.length();
        int start = 0;
        int maxi = 1;
        for (int i = 0; i < n; i++) {
            for (int j = i ; j < n; j++) {
                if (isPalindrome(i, j, s)) {
                    int currsize = j - i + 1;
                    if (currsize > maxi) {
                        maxi = currsize;
                        start = i;
                    }
                }
            }
        }
        return s.substring(start, start + maxi);
    }
}