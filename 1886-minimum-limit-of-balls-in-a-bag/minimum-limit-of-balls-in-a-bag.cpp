class Solution {
public:
    int minimumSize(vector<int>& nums, int maxOperations) {
        int i= 1;
        int j= 1e9;
        
        while (i<j) {
            int mid =i+(j-i)/2;
            long long operation = 0;
            for (int a: nums) {
                operation += (a-1)/mid;
            }
            if (operation>maxOperations) {
                i= mid+1;
            } else {
                j= mid;
            }
        }
        return i;
    }
};