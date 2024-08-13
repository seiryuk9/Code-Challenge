class Solution
{
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix)
    {
        int top = 0, bottom = matrix.size() - 1;
        int left = 0, right = matrix[0].size() - 1;
        int direction = 0; // 0: left to right; 1: top to bottom; 2: right to left; 3: bottom to top
        std::vector<int> result;

        if (matrix.size() == 0)
        {
            return result;
        }

        while (top <= bottom && left <= right)
        {
            // Print top row from left to right
            if (direction == 0)
            {
                for (int i = left; i <= right; ++i)
                {
                    result.emplace_back(matrix[top][i]);
                }
                direction = 1;
                top += 1;
            }

            // Print right column from top to bottom
            else if (direction == 1)
            {
                for (int i = top; i <= bottom; ++i)
                {
                    result.emplace_back(matrix[i][right]);
                }
                direction = 2;
                right -= 1;
            }

            // Print bottom row from right to left
            else if (direction == 2)
            {
                for (int i = right; i >= left; --i)
                {
                    result.emplace_back(matrix[bottom][i]);
                }
                direction = 3;
                bottom -= 1;
            }

            // Print right column from bottom to top
            else
            {
                for (int i = bottom; i >= top; --i)
                {
                    result.emplace_back(matrix[i][left]);
                }
                direction = 0;
                left += 1;
            }
        }

        return result;
    }
};