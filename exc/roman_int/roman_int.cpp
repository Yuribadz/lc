#include <iostream>
#include <string>
#include <map>

class Solution
{
public:
    int romanToInt(std::string s)
    {
        std::map<char, int> char_mapping;
        int answer = 0;
        size_t size = s.length();
        char_mapping = {{'I', 1}, {'V', 5}, {'X', 10}, {'L', 50},
            {'C', 100}, {'D', 500}, {'M', 1000}};
        for (size_t i = 0; i < size; ++i)
        {
            if (char_mapping[s[i]] < char_mapping[s[i + 1]])
            {
                answer -= char_mapping[s[i]];
            }
            else
            {
                answer += char_mapping[s[i]];
            }
        }
        return answer;
    }
};
int main()
{
    std::cout << Solution().romanToInt("LVIII") << std::endl;
    return 0;
}