class Solution {
public:
    int sortableIntegers(vector<int>& nums) {
       int n=nums.size();
        vector<int>s=nums;
        sort(s.begin(),s.end());
        int ts=0;
        for(int k=1;k<=n;k++){
            if(n%k !=0)
                continue;
            bool p=true;
            for(int i=0;i<n;i+=k){
                if(!isRotate(nums,s,i,k)){ 
                    p=false;
                    break;
                }
            }
            if(p) ts +=k;
        }
        return ts;
    }
    private:
    bool isRotate(vector<int>& a,vector<int>& b,int start,int k){
        for(int x=0;x<k;x++){
            bool m=true;
            for(int i=0;i<k;i++){
                if(a[start+i]!=b[start+(i+x)%k]){
                     m=false;
                    break;
                }
            }
            if(m)
                return true;
        }
        return false;
    }
};