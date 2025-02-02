#include <bits/stdc++.h> 
using namespace std;

// METHOD 1 TOP->DOWN
// vector<int>dp(35,-1);
// class Solution {
// public:
    
//     int fib(int n) {
//         if (dp[n]!=-1)
//         {
//             return dp[n];
//         }
//         if (n==1 || n==0)
//         {
//             return 1;
//         }
        
//         return dp[n]=fib(n-1)+fib(n-2);
//     }
// };

// int  main(int argc, const char** argv) {
//     Solution sol=Solution();
//     cout<<sol.fib(4);
//     return 0;
// }

// METHOD 2 == BOTTOM UP
// vector<int>dp(35,-1);
// class Solution {
// public:
    
//     int fib(int n) {
        
//         dp[0]=0;
//         dp[1]=1;

//         for (int i = 2; i <= n; i++)
//         {
//             dp[i]=dp[i-1]+dp[i-2];
//         }
    
//         return dp[n];
//     }
// };

// int  main(int argc, const char** argv) {
//     Solution sol=Solution();
//     cout<<sol.fib(4);
//     return 0;
// }

// METHOD3 BOOTOM UP WITH SPACE OPTIMISATION
vector<int>dp(35,-1);
class Solution {
public:
    
    int fib(int n) {
        
        if (n==1)
        {
            return 1;
        }
        else if (n==0)
        {
            return;
        }
        
        int la_1=1;
        int la_2=0;
        int curr;


        for (int i = 2; i <= n; i++)
        {
            curr=la_1+la_2;
            la_2=la_1;
            la_1=curr;
            
        }
    
        return curr;
    }
};

int  main(int argc, const char** argv) {
    Solution sol=Solution();
    cout<<sol.fib(4);
    return 0;
}