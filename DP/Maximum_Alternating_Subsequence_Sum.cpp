#include <bits/stdc++.h> 
using namespace std;

// vector<vector<long long>> dp(1e5+6, vector<long long>(2,-1));
long long dp[100005][2];
class Solution {
public:
    long long rec(vector<int> &nums,int curr,bool sign){

        if (curr==nums.size())
        {
            return 0;
        }
        if (dp[curr][sign]!=-1){
            return dp[curr][sign];
        }
       if (sign==false)
       {
         nums[curr]=-nums[curr];
       }
       long long take=rec(nums,curr+1,!sign)+nums[curr];
       
       long long skip=rec(nums,curr+1,sign);
    //    cout<<take<<" "<<skip<<" "<<curr<<endl;
       return dp[curr][sign]=max(skip,take);
    }
    long long maxAlternatingSum(vector<int>& nums) {

    //    cout<<dp[0][0];`
    memset(dp,-1,sizeof(dp));
       return rec(nums,0,true);
       
    }
};

int  main(int argc, const char** argv) {
    Solution sol=Solution();    
    vector<int> nums={4,2,5};
    
    cout<<sol.maxAlternatingSum(nums);
    return 0;
}   