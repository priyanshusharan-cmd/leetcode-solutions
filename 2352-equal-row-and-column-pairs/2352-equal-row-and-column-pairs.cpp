class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        int n = grid.size();

        map<vector<int>, int> rows;

        // Store frequency of each row
        for (int i = 0; i < n; i++) {
            rows[grid[i]]++;
        }

        int ans = 0;

        // Build each column and check if it exists as a row
        for (int j = 0; j < n; j++) {
            vector<int> col;

            for (int i = 0; i < n; i++) {
                col.push_back(grid[i][j]);
            }

            if (rows.find(col) != rows.end()) {
                ans += rows[col];
            }
        }

        return ans;
    }
};