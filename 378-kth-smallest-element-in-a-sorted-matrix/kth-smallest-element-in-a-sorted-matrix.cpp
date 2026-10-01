class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        int l = matrix[0][0];
        int h = matrix[n-1][n-1];

        while(l<h){
            int mid = l+(h-l)/2;
            int count = 0;
            int i,j;
            i = n-1; j =0;
            while(j<n){
                if(matrix[i][j] <= mid){
                    count+=i+1;
                    j++;
                    i=n-1;
                }else{
                    i--;
                    if(i<0){
                        j++;
                        i=n-1;
                    }
                }
            }
            if(count>=k){
                h = mid;
            }else{
                l = mid+1;
            }
        }
        return l;

    }
};