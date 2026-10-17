class Solution {
public:
    int hlp(int n){
        if(n == 0){
            return 0;
        }
        return hlp(n / 10) + n % 10;
    }
    int minSwaps(vector<int>& nums) {
        int n = nums.size();
        vector<int> t1(nums.begin(), nums.end());
        sort(t1.begin(), t1.end(), [&](int a, int b){
            int t1 = hlp(a), t2 = hlp(b);
            return t1 == t2 ? a < b : t1 < t2;
        });
        unordered_map<int, int> mp;
        for(int i = 0;i < n;i++){
            mp[nums[i]] = i;
        }
        int ans = 0;
        for(int i = 0;i < n;i++){
            if(nums[i] == t1[i]) continue;
            int j = mp[t1[i]];
            mp[nums[i]] = j;
            mp[t1[i]] = i;
            swap(nums[i], nums[j]);
            ans++;
        }
        return ans;
    }
};