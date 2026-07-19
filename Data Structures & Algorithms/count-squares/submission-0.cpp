//see again
class CountSquares {
public:

    unordered_map<int, unordered_map<int,int>> points;

    CountSquares() {}

    void add(vector<int> point) {

        int x = point[0];
        int y = point[1];

        points[x][y]++;
    }

    int count(vector<int> point) {

        int x = point[0];
        int y = point[1];

        int ans = 0;

        // Iterate through all points with same x-coordinate
        for (auto &[ny, freq] : points[x]) {

            if (ny == y)
                continue;

            int d = ny - y;

            // Right square
            ans += freq *
                   points[x + d][y] *
                   points[x + d][ny];

            // Left square
            ans += freq *
                   points[x - d][y] *
                   points[x - d][ny];
        }

        return ans;
    }
};