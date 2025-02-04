// // METHOD 1 RECURSION + MEMORISATION
#include <bits/stdc++.h>
using namespace std;

// // vector<int> dp(1000, -1);

// class Solution
// {
// public:


//     int rec(vector<int> &nums, int count,int end,vector<int> &dp)
//     {
//         if (count>end)
//         {
//             return 0;
//         }
//         if (dp[count]!=-1)
//         {
//             return dp[count];
//         }
        
//         int steal=rec(nums,count+2,end,dp)+nums[count];
//         int left=rec(nums,count+1,end,dp);
//         // HERE CHOICE IS TO CHOOSE CURRENT FOR ROBBING OR LEAVE THE CURRENT
//         return dp[count]=max(steal,left);
//     }

//     int rob(vector<int> &nums)
//     {
//         int n=nums.size();
        
//         if (n==1)
//         {
//             return nums[0];
//         }
        
//          vector<int> dp1(105,-1);
//          vector<int> dp2(105,-1);
//         return max(rec(nums, 1,n-1,dp1),rec(nums,0,n-2,dp2));
//     }
// };

// int main()
// {

//     Solution sol;
//     vector<int> nums = {94,40,49,65,21,21,106,80,92,81,679,4,61,6,237,12,72,74,29,95,265,35,47,1,61,397,52,72,37,51,1,81,45,435,7,36,57,86,81,72};
//     cout << sol.rob(nums);
//     return 0;
// }

// METHOD TABULATION + CONSTANT SPACE


class Solution
{
public:
    

    int rob(vector<int> &nums)
    {
       int n=nums.size();
       if (n<=3)
       {
         auto max_it= max_element(nums.begin(),nums.end());
         return *max_it;
       }

       int curr,prev1,prev2;
       prev2=nums[0];
       prev1=max(nums[0],nums[1]);
       for (int i = 2; i < n-1; i++)
       {
         curr=max(prev1,prev2+nums[i]);
         prev2=prev1;
         prev1=curr;
       }
       int ans_p1=curr;
       
       prev2=nums[1];
       prev1=max(nums[1],nums[2]);
       for (int i = 3; i < n; i++)
       {
         curr=max(prev1,prev2+nums[i]);
        prev2=prev1;
         prev1=curr;
       }
       return max(ans_p1,curr);
    }
};

int main()
{

    Solution sol;
    vector<int> nums = {200,3,140,20,10};
    cout << sol.rob(nums);
    return 0;
}
