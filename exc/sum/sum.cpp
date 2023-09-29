#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>

class Solution
{
public:
    std::vector<int> twoSum(std::vector<int> &nums, int target)
    {
        std::unordered_map<int, int> co_map;
        int complement {0};
        for(int i = 0; i < nums.size(); i++)
        {
            complement = target - nums[i];
            if(co_map.count(complement))
            {
                return {co_map[complement], i};
            } else {
                co_map[nums[i]] = i;
            }
        }
        return {};
    }
};

int main()
{
    std::vector<int> nums{6,3,15,50, 5, 4};
    Solution sol;
    int target = 9;
    std::string print_result{"Result = {"};
    const std::vector<int> res{sol.twoSum(nums, target)};
    for(const auto& elem : res)
    {
        if(elem == res.back())
        {
            print_result.append(std::to_string(elem) + "}");
        }
        else{
            print_result.append(std::to_string(elem) + ",");
        }
    }
    std::cout << print_result << std::endl;
    return 0;
}