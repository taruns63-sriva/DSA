class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int start = 1;
        int end = 1e9;
        
        while (start<end) {
            int k = start + (end - start) / 2;
            int hours = 0;
            
            for (int pile : piles) {
                hours += (pile +k- 1) /k;
            }
            if (hours <= h) {
                end= k; 
            } else {
                start = k + 1; 
            }
        }
        return start;
    }
};