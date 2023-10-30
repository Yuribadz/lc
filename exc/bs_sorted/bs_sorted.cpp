#include <iostream>
#include <vector>
#include <algorithm>


class Solution
{
public:
    int search(std::vector<int> &nums, int target)
    {
        int left = 0;
        int right = nums.size() - 1;
        int mid = 0;

        while (left <= right)
        {
            mid = left + (right - left) / 2;
            if (target == nums[mid])
                return mid;
            if (target < nums[mid])
            {
                right = --mid;
            }
            else
            {
                left = ++mid;
            }
        }

        return -1;
    }
};

int main()
{
    std::vector<int> nums = {5};
    std::cout << Solution().search(nums, 9) << std::endl;
    return 0;
}