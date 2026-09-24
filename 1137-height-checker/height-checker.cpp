class Solution {
public:
    int heightChecker(vector<int>& heights) {
        int cnt=0;
        vector<int>exp=heights;
        sort(exp.begin(),exp.end());
        for(int i=0;i<exp.size();i++)
        if(exp[i] != heights[i])
        cnt++;

     return cnt;
    }
};