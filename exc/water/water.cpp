#include <iostream>
#include <vector>

class Solution
{
public:
    int maxArea(std::vector<int> &height)
    {
        int answer = 0;
        std::vector<int>::iterator left = height.begin();
        std::vector<int>::iterator right = height.end() - 1;
        while (left < right)
        {
            const int minWater = std::min(*left, *right);
            answer = std::max(answer,
                              static_cast<int>(std::distance(left, right)) * 
                              minWater);
            while((left < right) && (*left <= minWater))
            {
                ++left;
            }
            while((left < right) && (*right <= minWater))
            {
                --right;
            }
        }
        return answer;
    }
};


int main()
{
    std::vector<int> heights{1, 8, 6, 2, 5, 4, 8, 3, 7};
    std::cout << Solution().maxArea(heights) << std::endl;
    return 0;
}