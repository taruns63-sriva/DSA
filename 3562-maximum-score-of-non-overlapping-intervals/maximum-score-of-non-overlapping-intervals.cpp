class Solution {
public:
    map< pair<int,int>, pair<long long, vector<int>> > dp;
    pair<long long, vector<int>> solve(vector<vector<int>>&v, int i, int k){
        if(dp.find({i,k}) != dp.end())
            return dp[{i,k}];
        int n = v.size();
        if(i == n)
            return {0, {}};
        if(k == 0)
            return {0, {}};
        pair<long long, vector<int>> res = solve(v, i+1, k);
        int left = i;
        int right = n;
        while(left < right){
            int mid = (left + right)/2;
            if(v[mid][0] > v[i][1]){
                right = mid;
            }
            else{
                left = mid + 1;
            }
        }
        int j = left;
        pair<long long, vector<int>> res2 = solve(v, j, k-1);
        res2.first += v[i][2];
        res2.second.push_back(v[i][3]);
        sort(res2.second.begin(), res2.second.end());
        if(res.first < res2.first){
            res = res2;
        } else if(res.first == res2.first){
            res.first = res2.first;
            res.second = min(res.second, res2.second);
        }
        return dp[{i,k}] = res;
    }
    vector<int> maximumWeight(vector<vector<int>>& intervals) {
        int n = intervals.size();
        vector<vector<int>> v;
        for(int i = 0; i < n; i++){
            int l = intervals[i][0];
            int r = intervals[i][1];
            int w = intervals[i][2];
            v.push_back({l,r,w,i});
        }
        sort(v.begin(), v.end());
        pair<long long, vector<int>> res = solve(v, 0, 4);
        return res.second;
    }
};