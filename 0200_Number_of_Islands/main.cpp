// Recursive
// T = O(n*m), S = O(n*m)
class Solution {
    void dfs(vector<vector<char>> &grid, vector<vector<bool>> &visit, int i,
             int j) {
        int n = grid.size(), m = grid[0].size();
        if (i < 0 || i >= n || j < 0 || j >= m || grid[i][j] == '0' ||
            visit[i][j] == true) {
            return;
        }
        visit[i][j] = true;
        dfs(grid, visit, i - 1, j);
        dfs(grid, visit, i, j + 1);
        dfs(grid, visit, i + 1, j);
        dfs(grid, visit, i, j - 1);
    }

  public:
    int numIslands(vector<vector<char>> &grid) {
        if (grid.empty() || grid[0].empty()) {
            return 0;
        }
        int n = grid.size(), m = grid[0].size();
        vector<vector<bool>> visit(n, vector<bool>(m));
        int count = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == '0' || visit[i][j] == true) {
                    continue;
                }
                count++;
                dfs(grid, visit, i, j);
            }
        }
        return count;
    }
};

// Iterator
// T = O(n*m), S = O(n*m)
class Solution {
    class Point {
      public:
        int x, y;
        Point(int x, int y) {
            this->x = x;
            this->y = y;
        }
    };
    void dfs(vector<vector<char>> &grid, vector<vector<bool>> &visit, int i,
             int j) {
        int n = grid.size(), m = grid[0].size();
        stack<Point *> st;
        st.push(new Point(i, j));
        while (!st.empty()) {
            Point *p = st.top();
            st.pop();
            if (p->x < 0 || p->x >= n || p->y < 0 || p->y >= m ||
                grid[p->x][p->y] == '0' || visit[p->x][p->y] == true) {
                continue;
            }
            visit[p->x][p->y] = true;
            st.push(new Point(p->x - 1, p->y));
            st.push(new Point(p->x, p->y + 1));
            st.push(new Point(p->x + 1, p->y));
            st.push(new Point(p->x, p->y - 1));
        }
    }

  public:
    int numIslands(vector<vector<char>> &grid) {
        if (grid.empty() || grid[0].empty()) {
            return 0;
        }
        int n = grid.size(), m = grid[0].size();
        vector<vector<bool>> visit(n, vector<bool>(m));
        int count = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == '0' || visit[i][j] == true) {
                    continue;
                }
                count++;
                dfs(grid, visit, i, j);
            }
        }
        return count;
    }
};
