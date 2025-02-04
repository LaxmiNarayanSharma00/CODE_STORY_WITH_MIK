#include <bits/stdc++.h>
using namespace std;

// METHOD 1 RECURSION + MEMORISATION
// vector<int> dp(1000, -1);

// class Solution
// {
// public:
//     int rec(vector<int> &nums, int count)
//     {

//         if (count < 0)
//         {
//             return 0;
//         }

//         if (dp[count] != -1)
//         {
//             return dp[count];
//         }

//         return dp[count] = max(rec(nums, count - 2) + nums[count], rec(nums, count - 1)); // HERE CHOICE IS TO CHOOSE CURRENT FOR ROBBING OR LEAVE THE CURRENT
//     }

//     int rob(vector<int> &nums)
//     {
//         int count = nums.size() - 1;
//         dp.assign(1000, -1);
//         dp[0] = nums[0]; // HERE BASE CASE DEFINED
//         if (count >= 1)
//         {
//             dp[1] = max(nums[0], nums[1]); // THIS IS ALSO BASE CASE
//         }

//         return rec(nums, count);
//     }
// };

// int main()
// {

//     Solution sol;
//     vector<int> nums = {2, 7, 9, 3, 1};
//     cout << sol.rob(nums);
//     return 0;
// }

// METHOD 2--> TABLUATION

// vector<int> dp(1000, -1);

// class Solution
// {
// public:

//     int rob(vector<int> &nums)
//     {
//         int count = nums.size() - 1;
//         dp.assign(1000, -1);
//         dp[0] = nums[0]; // HERE BASE CASE DEFINED
//         if (count >= 1)
//         {
//             dp[1] = max(nums[0], nums[1]); // THIS IS ALSO BASE CASE
//         }

//         for (int i = 2; i <= count; i++)
//         {
//             dp[i]=max(dp[i-1],dp[i-2]+nums[i]);
//         }
//         return dp[count];

//     }
// };

// int main()
// {

//     Solution sol;
//     vector<int> nums = {2, 7, 9, 3, 1};
//     cout << sol.rob(nums);
//     return 0;
// }

// METHOD 3 CONSTANT SPACE

// vector<int> dp(1000, -1);
class Solution
{
public:
    int rob(vector<int> &nums)
    {
        int count = nums.size() - 1;
        int curr, prev1, prev2;
        if (count == 0)
        {
            return nums[0];
        }
        else if (count == 1)
        {
            return max(nums[0], nums[1]);
        }
        else if (count > 1)
        {
            

            prev2 = nums[0]; // HERE BASE CASE DEFINED

            prev1 = max(nums[0], nums[1]); // THIS IS ALSO BASE CASE
            for (int i = 2; i <= count; i++)
            {
                curr = max(prev1, prev2 + nums[i]);
                prev2 = prev1;
                prev1 = curr;
            }
            
        }
        return curr;
    }
};

int main()
{

    Solution sol;
    vector<int> nums = {2, 7, 9, 3, 1};
    cout << sol.rob(nums);
    return 0;
}
