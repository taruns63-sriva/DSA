class Solution {
public:
    int getLength(vector<int>& nums) {
        int n = nums.size();
        int ans = 1;

        for (int i = 0; i < n; i++) {
            unordered_map<int, int> cnt;
            unordered_map<int, int> freq;

            for (int j = i; j < n; j++) {
                int x = nums[j];

                if (cnt[x] > 0) {
                    freq[cnt[x]]--;

                    if (freq[cnt[x]] == 0)
                        freq.erase(cnt[x]);
                }
                cnt[x]++;
                freq[cnt[x]]++;

                if (cnt.size() == 1) {
                    ans = max(ans, j - i + 1);
                }
                else if (freq.size() == 2) {
                    auto it = freq.begin();
                    int a = it->first;
                    ++it;
                    int b = it->first;

                    int mn = min(a, b);
                    int mx = max(a, b);

                    if (mx == 2 * mn)
                        ans = max(ans, j - i + 1);
                }
            }
        }
        return ans;
    }
};