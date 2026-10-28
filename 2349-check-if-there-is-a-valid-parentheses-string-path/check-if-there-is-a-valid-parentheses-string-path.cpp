class Solution {
public:
    bool hasValidPath(vector<vector<char>>& grid) {
        if(grid[0][0] == ')')
        return false;

        int m=grid.size(),n=grid[0].size();
        if((m + n) % 2 == 0) return false;
        queue<pair<int,pair<int,int>>>q;
        q.push({1,{0,0}});

        int dir[2][2]={{1,0},{0,1}};

        bool vis[101][101][101]={};
        vis[1][0][0]=true;

        while(!q.empty()){
            auto it=q.front();
            q.pop();

            int cnt=it.first;
            int r=it.second.first;
            int c=it.second.second;

            int remaining = (m-1-r) + (n-1-c);
            if(cnt > remaining) continue;

            if(r == m-1 && c == n-1){
                if(cnt == 0)
                return true;
            }

            for(auto &d : dir){
                int newr=r+d[0];
                int newc=c+d[1];


                if(newr >= 0 && newr < m && newc >= 0 && newc < n){
                    int newCnt = cnt + (grid[newr][newc] == '(' ? 1 : -1);

                    if(newCnt >= 0 && !vis[newCnt][newr][newc]) {
                        vis[newCnt][newr][newc]=true;
                        q.push({newCnt,{newr,newc}});
                    }
                }
            }
        }
        return false;
    }
};