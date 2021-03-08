class Solution {
public:
	int dfs(vector<vector<int>>& grid, int r, int c) {
		//���ж������Ƿ��ڷ�Χ�ڣ����жϺϷ����������Ƿ�Ϊ0���������׵����������
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