#include <iostream>
#include <vector>

class Rod
{
public:
    std::pair<int, std::vector<int>> cutRod(const std::vector<int> &prices) const
    {
        if (prices.size() > INT_MAX)
        {
            std::cout << "Unimplemented vectorized solution\n";
            return std::make_pair(0, std::vector<int>());
        }
        int size = static_cast<int>(prices.size());
        std::vector<int> revenues(size + 1, 0);
        std::vector<int> choices(size + 1, 0);
        int max_revenue;
        for (int rod_len = 1; rod_len <= size; rod_len++)
        {
            max_revenue = INT_MIN;
            for (int cut = 0; cut < rod_len; cut++)
            {
                if (max_revenue < prices[cut] +
                                      revenues[rod_len - cut - 1])
                {
                    max_revenue = prices[cut] +
                                  revenues[rod_len - cut - 1];
                    choices[rod_len] = cut + 1;
                }
            }
            revenues[rod_len] = max_revenue;
        }
        std::vector<int> cut_res;
        while (size > 0)
        {
            cut_res.push_back(choices[size]);
            size = size - choices[size];
        }
        return std::make_pair(revenues[prices.size()], cut_res);
    }
};

int main()
{
    Rod rod{};
    std::vector<int> prices{1, 5, 8, 9, 10, 17, 17};
    const auto [revenue, cuts] = rod.cutRod(prices);
    std::cout << "Maximum Revenue = " << revenue << " Cuts = ";
    std::cout << "Cut on: ";
    for (const auto &number : cuts)
    {
        std::cout << number << " ";
    }
    std::cout << std::endl;

    return 0;
}