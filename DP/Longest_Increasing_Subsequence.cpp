#include <bits/stdc++.h> 
using namespace std;

int dp[2505][2505];
class Solution {
public:
    int rec(vector<int>& nums,int curr,int prev_idx){
        int take=0;
        if (curr==nums.size())
        {
            return 0;
        }
        if (prev_idx!=-1 && dp[curr][prev_idx]!=-1)
        {
            return dp[curr][prev_idx];
        }
        if (prev_idx==-1 || nums[curr]>nums[prev_idx])
        {
             take=rec(nums,curr+1,curr)+1;
        }
        
        int left=rec(nums,curr+1,prev_idx);
        if(prev_idx!=-1){
            return dp[curr][prev_idx]=max(left,take);
        }
        return max(left,take);
    }
    int lengthOfLIS(vector<int>& nums) {
        memset(dp,-1,sizeof(dp));
        return rec(nums,0,-1);
    }
};


int  main(int argc, const char** argv) {
    Solution sol=Solution();    
    vector<int> nums={7,7,7,7,7,7,7};
    
    
    cout<<sol.lengthOfLIS(nums);
    return 0;
}   