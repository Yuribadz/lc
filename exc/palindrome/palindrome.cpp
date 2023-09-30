#include <string>
#include <algorithm>
#include <iostream>

class Solution
{
public:
      bool isPalindrome(int x)
      {
            std::string forward = std::to_string(x);
            std::string reverse{forward};
            std::reverse(reverse.begin(), reverse.end());
            if (forward == reverse)
                  return true;
            return false;
      }
};

int main()
{
      int num = 6556;
      std::cout << Solution().isPalindrome(num) << std::endl;
      return 0;
}