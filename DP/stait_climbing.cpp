#include<bits/stdc++.h>
using namespace std;
vector<int> dp(100,-1);

// METHOD 1 REC +MEMORISATION
class Solution {
public:
    
    int rec(int n)
    {    
        if(n<=2){
            return n;
        }
        if(dp[n]!=-1){
            return dp[n];
        }
        return dp[n]=rec(n-1)+rec(n-2);
    }
    
    int climbStairs(int n) {

        return rec(n);
    }
};

// METHOD 2- TABULATION

class Solution {
public:
    

    
    int climbStairs(int n) {
        dp[0]=1;
        dp[1]=1;
        
        for (int i = 2; i < n; i++)
        {
            dp[i]=dp[i-1]+dp[i-2];
        }
        return dp[n-1];
        
       
    }
};
