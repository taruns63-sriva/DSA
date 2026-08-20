class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        int m = mat.size(), n = mat[0].size();
        vector<bool>seen(m, false);
        vector<int>ans;
        for(int col=0;col<n;col++) {
            for(int row=0;row< m;row++) {
                if(mat[row][col] == 0 && !seen[row]) {
                    ans.push_back(row);
                    seen[row] = true;
                    k--;
                    if(k==0) return ans;
                }
            }
        }
        for(int row=0;row<m;row++) {
            if(!seen[row]) {
                ans.push_back(row);
                seen[row] = true;
                k--;
                if(k==0) return ans;
            }
        }
        return ans;
    }
};