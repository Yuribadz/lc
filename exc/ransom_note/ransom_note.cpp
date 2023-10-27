#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

class Solution {
public:
    bool canConstruct(std::string ransomNote, std::string magazine) {
        if(ransomNote.empty() || magazine.empty() || (ransomNote.size() > magazine.size()))
        {
            return false;
        }
        std::vector<int> result(256);
        for (const auto &elem : magazine) {
            result[elem - 'a']++;
        }
        for (const auto &elem: ransomNote){
            result[elem - 'a']--;
        }
        for (const auto elem : result){
            if (elem < 0){
                return false;
            }
        }
        return true;
    }
};


int main()
{
    std::cout << Solution().canConstruct("aa","ab") << std::endl;
    return 0;
}