class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
         int n = arr.size();
        vector<int> min_len(n, INT_MAX);
        
        int left = 0;
        int current_sum = 0;
        int ans = INT_MAX;
        int current_min_len = INT_MAX;
        
        for (int right = 0; right < n; ++right) {
            current_sum += arr[right];
            while (current_sum > target) {
                current_sum -= arr[left];
                left++;
            }
            if (current_sum == target) {
                int curr_len = right - left + 1;
                if (left > 0 && min_len[left - 1] != INT_MAX) {
                    ans = min(ans, curr_len + min_len[left - 1]);
                }
                
                current_min_len = min(current_min_len, curr_len);
            }
            min_len[right] = current_min_len;
        }
        
        return (ans == INT_MAX) ? -1 : ans;
    }
};