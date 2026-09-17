class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {

        int n = cardPoints.size();
        int total = 0;

        for(int x : cardPoints)
            total += x;
        if(k == n)
            return total;
        int middle = n - k;

        int curr = 0;
        for(int i = 0; i < middle; i++)
            curr += cardPoints[i];
        int minSum = curr;

        for(int i = middle; i < n; i++) {
            curr += cardPoints[i];
            curr -= cardPoints[i-middle];
            minSum = min(minSum, curr);
        }
        return total - minSum;
    }
};