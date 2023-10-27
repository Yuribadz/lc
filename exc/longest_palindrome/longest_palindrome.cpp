#include <string>
#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <bitset>

class Solution {
public:
    int longestPalindrome(std::string s) {
        std::unordered_map<char,int> char_map;
        for(const auto& elem: s) 
        {
            char_map[elem]++;
        }

        int count = 0;
        bool odd = false;

        for(const auto elem: char_map)
        {
            if(elem.second % 2 == 0) 
            {
                  count += elem.second;
            }
            else
            {
                count += elem.second-1;
                odd = true;
            }
        }

        return (odd) ? count + 1 : count;
    }
};

class BitSolution
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

      std::cout << Solution().longestPalindrome("abccccddfgh") << std::endl;
      std::cout << BitSolution().longestPalindrome("abccccddfgh") << std::endl;
      return 0;
}