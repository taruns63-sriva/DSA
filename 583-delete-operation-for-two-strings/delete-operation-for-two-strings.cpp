class Solution {
public:
    int minDistance(string s1, string s2) {
        int n1 = s1.size() ;
    int n2 = s2.size() ;

    vector<int> prev(n2 + 1 , 0) ; 

    int idx1 = n1 - 1 ;
    int idx2 = n2 -  1 ;
    
    for(int i = 1 ; i <= n1 ; i++) {
        vector<int> curr(n2 + 1 , 0) ;

        for(int j = 1 ; j <= n2 ; j++) {
            int m = 0 ;
            int nm = 0;

            if(s1[i - 1] == s2[j - 1]) curr[j] = 1 + prev[j -1] ;
            else curr[j] = max(prev[j] , curr[j - 1]) ;

        }
        prev = curr ;
    }
        return  (n1 + n2) - 2*prev[n2] ;
    }
};