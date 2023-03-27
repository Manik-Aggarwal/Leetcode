//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    
    //find a power of 2 which is less than or equal to n, eg n=11, nearest power is 8
    int countpower(int n){ 
       int x=0;
         while((pow(2,x))<=n){
             x++;
         }
        return x-1;
    }

    int countSetBits(int n){  
        if(n==0) return 0;
        
        int x = countpower(n);
        int x1 = x*(pow(2,x-1));          //x*(1<<(x-1));  
        int x2 = n - pow(2,x) + 1;          //n-(1<<x)+1;
        int rest = n - pow(2,x);            //n-(1<<x);
        
        int ans = x1 + x2 + countSetBits(rest);

        return ans;
    }
};


//{ Driver Code Starts.

// Driver code
int main()
{
	 int t;
	 cin>>t;// input testcases
	 while(t--) //while testcases exist
	 {
	       int n;
	       cin>>n; //input n
	       Solution ob;
	       cout << ob.countSetBits(n) << endl;// print the answer
	  }
	  return 0;
}

// } Driver Code Ends