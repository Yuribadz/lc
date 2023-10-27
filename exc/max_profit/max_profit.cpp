#include <iostream>
#include <vector>
#include <string>

class Solution {
public:
    int maxProfit(std::vector<int>& prices) {
        if(prices.empty())
        {
            return 0;
        }
        int buy = prices[0]; 
        int sell = 0;
        for(const auto& price : prices)
        {
            if(price < buy)
            {
                buy = price;
            }
            if((price - buy) > sell)
            {
                sell = price - buy;
            }
        }
        return sell;
    }
};

int main()
{
    std::vector<int> prices{7,6,4,3,1};
    std::cout << Solution().maxProfit(prices) << std::endl;
    return 0;
}