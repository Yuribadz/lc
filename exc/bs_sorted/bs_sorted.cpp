#include <iostream>
#include <vector>
#include <algorithm>

class Solution {
public:
    int search(std::vector<int>& nums, int target) {
        if(nums.empty())
        {
            return -1;
        }
        int left = 0;
        int right = nums.size() - 1;
        int mid = 0;
        while(left < right)
        {
            if(target == nums[mid])
            {
                return mid;
            }
            mid = left + ((right - left) / 2);
            if(nums[mid] > target)
            {
                --right;
            }
            else{
                ++left;
            }
        }
        return -1;
        
    }
};


int main()
{
    std::vector<int> nums = {-1,0,3,5,9,12};
    std::cout << Solution().search(nums, 9) << std::endl;
    return 0;
}