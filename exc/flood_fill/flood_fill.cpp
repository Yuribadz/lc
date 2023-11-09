#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

class DfsSolution
{
public:
    std::vector<std::vector<int>>
    floodFill(std::vector<std::vector<int>> &image, int sr, int sc, int color)
    {
        startColor_ = image[sr][sc];
        newColor_ = color;
        rowMaxIdx_ = image.size() - 1;
        colMaxIdx_ = image[0].size() - 1;

        if (startColor_ != newColor_)
            doFill(image, sr, sc);

        return image;
    }

private:
    inline void doFill(std::vector<std::vector<int>> &image,
                       const int row, const int column)
    {
        if (image[row][column] != startColor_)
            return;

        image[row][column] = newColor_;

        if (row > 0)
            doFill(image, row - 1, column);

        if (row < rowMaxIdx_)
            doFill(image, row + 1, column);

        if (column > 0)
            doFill(image, row, column - 1);

        if (column < colMaxIdx_)
            doFill(image, row, column + 1);
    }

    int startColor_;
    int newColor_;
    int rowMaxIdx_;
    int colMaxIdx_;
};

class Solution
{
public:
    int validCoord(int x, int y, int n, int m)
    {

        if (x < 0 || y < 0)
        {
            return 0;
        }
        if (x >= n || y >= m)
        {
            return 0;
        }
        return 1;
    }

    std::vector<std::vector<int>> floodFill(
        std::vector<std::vector<int>> &image, int sr, int sc, int color)
    {
        int rows_num = image.size();
        int cols_num = image[0].size();
        std::vector<std::vector<int>> visited(rows_num,
                                              std::vector<int>(cols_num));
        std::queue<std::pair<int, int>> obj;

        obj.push({sr, sc});

        visited[sr][sc] = 1;
        while (!obj.empty())
        {

            std::pair<int, int> coord = obj.front();
            int sr = coord.first;
            int sc = coord.second;
            int preColor = image[sr][sc];

            image[sr][sc] = color;
            obj.pop();

            if (validCoord(sr + 1, sc, rows_num, cols_num) && visited[sr + 1][sc] == 0 && image[sr + 1][sc] == preColor)
            {
                obj.push({sr + 1, sc});
                visited[sr + 1][sc] = 1;
            }

            if (validCoord(sr - 1, sc, rows_num, cols_num) && visited[sr - 1][sc] == 0 && image[sr - 1][sc] == preColor)
            {
                obj.push({sr - 1, sc});
                visited[sr - 1][sc] = 1;
            }

            if (validCoord(sr, sc + 1, rows_num, cols_num) && visited[sr][sc + 1] == 0 && image[sr][sc + 1] == preColor)
            {
                obj.push({sr, sc + 1});
                visited[sr][sc + 1] = 1;
            }

            if (validCoord(sr, sc - 1, rows_num, cols_num) && visited[sr][sc - 1] == 0 && image[sr][sc - 1] == preColor)
            {
                obj.push({sr, sc - 1});
                visited[sr][sc - 1] = 1;
            }
        }
        return image;
    }
};

int main()
{
    std::vector<std::vector<int>> nums{{1, 1, 1}, {1, 1, 0}, {1, 0, 1}};
    Solution().floodFill(nums, 1, 1, 2);
    for (int i = 0; i < nums.size(); i++)
    {
        for (int j = 0; j < nums[0].size(); j++)
        {
            std::cout << nums[i][j] << " ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
    return 0;
}