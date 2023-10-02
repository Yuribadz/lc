#include <iostream>
#include <vector>

class Solution
{
public:
    std::string longestCommonPrefix(std::vector<std::string> &strs)
    {
        if (strs.size() == 0)
        {
            return {};
        }
        if (strs.size() == 1)
        {
            return strs.front();
        }
        std::string pref_word = strs[0];
        int cnt = 0;
        for (int i = 1; i < strs.size(); ++i)
        {
            for (cnt = 0; cnt < std::min(pref_word.size(), strs[i].size()); ++cnt)
            {
                if (pref_word[cnt] != strs[i][cnt])
                {
                    break;
                }
            }
            pref_word = pref_word.substr(0, cnt);
        }
        return pref_word;
    }
};

int main()
{
    std::vector<std::string> vect{"dous", "dout", "dough", "doest", "douxy"};
    std::cout << Solution().longestCommonPrefix(vect) << std::endl;
    return 0;
}