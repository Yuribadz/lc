#include <string>
#include <algorithm>
#include <iostream>
#include <bitset>

class Solution
{
public:
      int longestPalindrome(std::string s)
      {
            std::bitset<64> bits(0);
            for (char c : s)
            {
                  bits.flip(c - 'A');
            }
            return s.size() - bits.count() + bits.any();
      }
};

int main()
{

      std::cout << Solution().longestPalindrome("a") << std::endl;
      return 0;
}