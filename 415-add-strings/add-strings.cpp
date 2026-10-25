class Solution {
public:
    string addStrings(string nums1, string nums2) {
        string res = "";
        int i = nums1.length()-1, j = nums2.length()-1;
        int carry = 0;
        while (i>=0 || j>=0 || carry) {
            int sum = 0;
            if (i>=0) {
                sum += (nums1[i--] - '0');
            }
            if (j>=0) {
                sum += (nums2[j--] - '0');
            }
            sum += carry;
            carry = sum / 10;
            sum = sum % 10;
            res += to_string(sum);
        }
        reverse(res.begin(), res.end());
        return res;
    }
};