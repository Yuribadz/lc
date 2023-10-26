#include <iostream>
#include <vector>
#include <algorithm>

class Solution {
public:
    bool isAnagram(std::string s, std::string t) const noexcept{
        if(s.size() != t.size())
        {
            return false;
        }
        std::vector<int> occurence(256,0);
        for(int i = 0; i < s.size(); ++i)
        {
            occurence[static_cast<int>(s[i])]++;
            occurence[static_cast<int>(t[i])]--;
        }

        return std::all_of(occurence.begin(), occurence.end(), 
            [](int count) { return count == 0; });
    }
};


int main()
{
    std::string one("anagram");
    std::string two = ("nagram");
    std::cout << Solution().isAnagram(one,two) << std::endl;
    return 0;
}