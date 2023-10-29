#include <iostream>
#include <vector>
#include <algorithm>

bool isBadVersion(int build)
{
    if(build >= 4)
    {
        return true;
    }
    else{
        return false;
    }
}

class Solution {
public:

    int firstBadVersion(int n) {
        int cycles = 1;
        if(n == 0)
        {
            return 0;
        }
        if(n == 1)
        {
            return isBadVersion(n);
        }
        int rightBound = n;
        int leftbound = 1;
        int mid = 0;
        while(leftbound <= rightBound)
        {
            mid = leftbound + (rightBound - leftbound) / 2;
            if(isBadVersion(mid))
            {
                rightBound = --mid;
            }
            else
            {
                leftbound = ++mid;
            }
        }
        return leftbound;
    }
};


int main()
{
    std::cout << Solution().firstBadVersion(800) << std::endl;
    return 0;
}