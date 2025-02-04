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

// METHOD 1 RECURSION + MEMORISATION


class Solution
{
public:
    

    int rob(vector<int> &nums)
    {
        int count = nums.size() - 2;

         vector<int> dp1(105,-1);
         vector<int> dp2(105,-1);

         dp1[0] = nums[0]; // HERE BASE CASE DEFINED
        if (count >= 1)
        {
            dp1[1] = max(nums[0], nums[1]); // THIS IS ALSO BASE CASE
        }
        
        for (int i = 2; i <= count; i++)
        {
            dp1[i]=max(dp1[i-1],dp1[i-2]+nums[i]);
        }


        int count2 = nums.size() - 1;
   
         dp2[1] = nums[1]; // HERE BASE CASE DEFINED
        if (count2 >= 1)
        {
            dp2[2] = max(nums[1], nums[2]); // THIS IS ALSO BASE CASE
        }
        
        for (int i = 3; i <= count2; i++)
        {
            dp2[i]=max(dp2[i-1],dp2[i-2]+nums[i]);
        }
        return max(dp1[count],dp2[count2]);

    }
};

int main()
{

    Solution sol;
    vector<int> nums = {1,2,3};
    cout << sol.rob(nums);
    return 0;
}
