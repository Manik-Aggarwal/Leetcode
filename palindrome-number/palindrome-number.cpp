class Solution {
public:
    bool isPalindrome(int x) {
        int cx = x;
        int ans = 0;
        while(x != 0){
        int digit = x % 10;
        if((ans > INT_MAX/10) || (ans < INT_MIN/10) || x<0){
                return false;
        }
        ans = ans * 10 + digit;
        x = x/10;
        }
        
        if(cx != ans){
            return false;
        }
        
        return true;
    }
};