#include <vector>
#include <queue>
#include <climits>

using namespace std;

class Solution {
public:
    void wallsAndGates(vector<vector<int>>& grid) {
        if (grid.empty() || grid[0].empty()) return;

        int m = grid.size();
        int n = grid[0].size();

        using p = pair<int, int>;
        queue<p> q;

        // Push all gates (0s) into the queue as BFS starting points
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 0) {
                    q.push({i, j});
                }
            }
        }

        // Direction vectors for moving UP, DOWN, LEFT, RIGHT
        vector<pair<int, int>> dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

        auto isSafe = [&](int x, int y) {
            // Checks bounds AND ensures the cell is an unvisited empty room (INT_MAX)
            return x >= 0 && x < m && y >= 0 && y < n && grid[x][y] == INT_MAX;
        };

        int dis = 1;
        while (!q.empty()) {
            int sz = q.size(); // Renamed to 'sz' to prevent variable shadowing
            while (sz--) {
                auto [i, j] = q.front();
                q.pop();

                for (auto& dir : dirs) {
                    int new_i = i + dir.first;
                    int new_j = j + dir.second;

                    if (isSafe(new_i, new_j)) {
                        grid[new_i][new_j] = dis;
                        q.push({new_i, new_j});
                    }
                }
            }
            dis++;
        }
    }
};
