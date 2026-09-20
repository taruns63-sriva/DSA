class Solution {
public:
    using ll=long long;
    ll countIntersectingIntervals(vector<vector<int>>& A) {
        int n=A.size();
        vector<pair<ll,ll>>P;
        for(int i=0;i<n;++i){
            P.push_back({A[i][0],-1});
            P.push_back({A[i][1],1});
        }
        sort(begin(P),end(P));
        ll a=0,res=0;
        for(int i=0;i<P.size();++i){
            if(P[i].second==-1){
                res+=a;
                ++a;
            }
            else{
                --a;
            }
        }
        return res;
    }
};