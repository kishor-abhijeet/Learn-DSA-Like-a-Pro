class Solution {
public:
    typedef pair<int, int> p;
    vector<vector<int>> dir{{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        queue<p> q;
        int freshOranges = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 2) {
                    q.push({i, j});
                } else if (grid[i][j] == 1)
                    freshOranges++;
            }
        }

        if (freshOranges == 0)
            return 0;
        auto isSafe = [&](int x, int y) {
            return x >= 0 && x < grid.size() && y >= 0 && y < grid[x].size() &&
                   grid[x][y] == 1;
        };
         int time = 0;

        while (!q.empty()) {
            int n = q.size();
            while (n--) {
                p curr = q.front();
                q.pop();
                int i = curr.first;
                int j = curr.second;

                for (int x = 0; x < 4; x++) {
                    int new_i = i + dir[x][0];
                    int new_j = j + dir[x][1];
                    if (isSafe(new_i, new_j)) {
                        
                            grid[new_i][new_j] = 2;
                            q.push({new_i, new_j});
                            freshOranges--; 
                        
                    }
                }
                
            }
            time++;
        }

        if (freshOranges == 0)
            return time - 1;
        return -1;
    }
};
