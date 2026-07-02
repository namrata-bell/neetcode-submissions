class Solution {
public:
    void dfs(int row, int col, vector<vector<int>>& image,
             int oldColor, int newColor) {

        int n = image.size();
        int m = image[0].size();

        if (row < 0 || row >= n || col < 0 || col >= m)
            return;

        if (image[row][col] != oldColor)
            return;

        image[row][col] = newColor;

        dfs(row + 1, col, image, oldColor, newColor);
        dfs(row - 1, col, image, oldColor, newColor);
        dfs(row, col + 1, image, oldColor, newColor);
        dfs(row, col - 1, image, oldColor, newColor);
    }
//Time Complexity: O(n × m)
//Space Complexity: O(n × m) (due to the recursion stack)
    vector<vector<int>> floodFill(vector<vector<int>>& image,
                                  int sr, int sc, int color) {

        int oldColor = image[sr][sc];

        if (oldColor == color)
            return image;

        dfs(sr, sc, image, oldColor, color);

        return image;
    }
};