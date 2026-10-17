class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int n = nums.size();
        auto getsum = [](int x) {
            int s = 0;
            while (x > 0) {
                s += x % 10;
                x /= 10;
            }
            return s;
        };
        vector<pair<pair<int, int>, int>> a(n);
        for (int i = 0; i < n; i++) {
            a[i] = {{getsum(nums[i]), nums[i]}, i};
        }
        sort(a.begin(), a.end());
        vector<int> target(n);
        for (int i = 0; i < n; i++) {
            target[a[i].second] = i;
        }
        vector<bool> vis(n, false);
        int ans = 0;
        for (int i = 0; i < n; i++) {
            if (vis[i] || target[i] == i) {
                continue;
            }
            int len = 0;
            int cur = i;
            while (!vis[cur]) {
                vis[cur] = true;
                cur = target[cur];
                len++;
            }
            if (len > 1) {
                ans += len - 1;
            }
        }
        return ans;
    }
};