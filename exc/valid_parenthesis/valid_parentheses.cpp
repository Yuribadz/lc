#include <iostream>
#include <vector>
#include <string>

class Solution {
public:
    bool isValid(std::string s) {
        if(s.empty())
        {
            return false;
        }
        std::vector<char> parentheses;
        for(const auto& elem: s)
        {
            if((elem == '{') || (elem == '(') || (elem == '['))
            {
                parentheses.push_back(elem);
            }
            else
            {
                if(parentheses.empty())
                {
                    return false;
                }
                else if(elem == '}' && '{' != parentheses.back())
                {
                    return false;
                }
                else if(elem == ')' && '(' != parentheses.back())
                {
                    return false;
                }
                else if(elem == ']' && '[' != parentheses.back())
                {
                    return false;
                }
                else{
                    parentheses.pop_back();
                }
            }
        }
        return parentheses.empty();
        
    }
};

int main()
{
    
    std::cout << Solution().isValid("]") << std::endl;
    return 0;
}