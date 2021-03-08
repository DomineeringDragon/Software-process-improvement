class Solution {
public:
	int dfs(vector<vector<int>>& grid, int r, int c) {
		//先判断坐标是否在范围内，在判断合法坐标的面积是否为0，否则容易导致数组溢出
		if (r >= grid.size() || r < 0 || c < 0 || c >= grid[0].size() || grid[r][c] == 0) { return 0; }
		grid[r][c] = 0;

		return 1 + dfs(grid, r - 1, c) + dfs(grid, r + 1, c) + dfs(grid, r, c + 1) + dfs(grid, r, c - 1);
	}
	int maxAreaOfIsland(vector<vector<int>>& grid) {
		if (grid.empty() || grid[0].empty()) { return 0; }
		int m = grid.size();
		int n = grid[0].size();
		int maxArea = 0;
		for (int i = 0; i < m; ++i) {
			for (int j = 0; j < n; ++j) {
				maxArea = max(maxArea, dfs(grid, i, j));
			}
		}
		return maxArea;
	}
};