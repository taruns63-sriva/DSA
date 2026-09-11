class Solution {
public:
    bool isBalanced(string num) { int n=num.size();
        int even=0;
        int odd=0;

        for(int i=0;i<n;i++){
            int digit=num[i]-'0';
            if(i%2==0){
                even += digit;
            } else{
                odd += digit;
            }
        } 
        return even==odd;
    }
};