#include <iostream>
#include <math.h>
#include <algorithm>
#include <vector>
using namespace std;

class Solution
{
public:
    int majorityElement(vector<int> &nums)
    {
        // sort(nums.begin(), nums.end());
        quicksort(nums, 0, nums.size() - 1);
        return nums[nums.size() / 2];
    }

    void quicksort(vector<int> &nums, int l, int r)
    {
        if (l < r)
        {
            int m = partition(nums, l, r);
            quicksort(nums, l, m - 1);
            quicksort(nums, m + 1, r);
        }
    }

    int partition(vector<int> &nums, int l, int r)
    {
        int mid = nums[l];
        int i = l, j = r;
        while (i < j)
        {
            while (i < j && nums[j] <= mid)
                j--;
            while (i < j && nums[i] >= mid)
                i++;
            if (i < j)
                swap(nums[i], nums[j]);
        }
        swap(nums[i], nums[l]);

        return i;
    }
};
int main()
{
    vector<int> nums;
    int item;
    while (cin >> item)
    {
        nums.push_back(item);
        if (cin.get() == '\n')
            break;
    }

    Solution s;
    int res = s.majorityElement(nums);
    cout << res << endl;
    return 0;
}