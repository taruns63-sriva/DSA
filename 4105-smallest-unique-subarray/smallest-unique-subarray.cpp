class Solution {
public:
    vector<unsigned long long> computeHash(const vector<int>& nums) {
        vector<unsigned long long> hash(nums.size() + 1, 0);
        unsigned long long p = 131071;

        for(int i = 0; i < nums.size(); i++){
            hash[i+1] = (hash[i] + (unsigned long long)nums[i]) * p;
        }
        return hash;
    }

    int smallestUniqueSubarray(vector<int>& nums) {
        int n = nums.size();
        int lo = 1, hi = n;
        vector<unsigned long long> hash = computeHash(nums);
        int ans = hi;

        vector<unsigned long long> power(n + 1, 1);
        unsigned long long p = 131071;

        for(int i = 1; i <= n; i++){
            power[i] = power[i-1] * p;
        }

        auto check = [&](int len) {
            unordered_map<unsigned long long, int> mp;

            for(int i = len; i <= n; i++){
                unsigned long long curHash = hash[i] - hash[i-len] * power[len];
                mp[curHash]++;
            }

            for(auto& it : mp){
                if(it.second == 1){
                    return true;
                }
            }
            return false;
        };

        while(lo <= hi){
            int mid = lo + (hi - lo) / 2;

            if(check(mid)){
                ans = mid;
                hi = mid - 1;
            } else {
                lo = mid + 1;
            }
        }
        return ans;
    }
};