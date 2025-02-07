#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    int maxSubArray(vector<int> &nums)
    {
        vector<int> dp(nums.size());
        dp[0] = nums[0];
        int res = nums[0];
        for (int i = 1; i < nums.size(); i++)
        {
            dp[i] = max(nums[i], dp[i - 1] + nums[i]);
            res = max(res, dp[i]);
        }

        return res;
    }
};

int main()
{
    vector<int> nums;
    int c;
    while (cin >> c)
    {
        nums.push_back(c);
        if (cin.get() == '\n')
            break;
    }

    Solution s;
    int res = s.maxSubArray(nums);
    cout << res << endl;
    return 0;
}