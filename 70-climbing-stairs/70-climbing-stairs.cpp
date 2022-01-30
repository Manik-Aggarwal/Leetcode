//1st approach
// class Solution {
// public:
//     int climbStairs(int n) {
//         //base case
//         if(n < 0) return 0;
//         if(n == 0) return 1;
        
//         int ans = climbStairs(n-1) + climbStairs(n-2);
//         return ans;
//     } 
// };

//2nd approach
// class Solution {
// public:
//     int climbStairs(int n) {
//         int temp[n + 1];
//         temp[0] = 1;
//         temp[1] = 1;
         
//         for(int i = 2; i <(n + 1); ++i) temp[i] = temp[i - 1] + temp[i - 2];
        
//         return temp[n];
//     }
// };

//3rd approach
class Solution {
    int F[46];
public:
    Solution(){
        memset(F, -1, sizeof(F));
    }
    
    int climbStairs(int n) {
        if(n == 0 || n == 1){
            return F[n] = 1;
        }
        else{
            if(F[n-2] == -1) F[n-2] = climbStairs(n-2); 
            if(F[n-1] == -1) F[n-1] = climbStairs(n-1); 
        }
        
        return F[n-2] + F[n-1];
    }
};