class Solution {
public:
	vector<int> dircetion{ -1,0,1,0,-1 };
	void dfs(const vector<vector<int>>& matrix, vector<vector<bool>>& canReach, int r, int c) {
		if (canReach[r][c]) {
			return;
		}
		canReach[r][c] = true;
		int x, y;
		for (int i = 0; i < 4; i++) {
			x = dircetion[i] + r;
			y = dircetion[i + 1] + c;
			if (x >= 0 &&
				x < matrix.size() &&
				y >= 0 && y < matrix[0].size() &&
				matrix[r][c] <= matrix[x][y])
			{
				dfs(matrix, canReach, x, y);
			}
		}
	}
	vector<vector<int>> pacificAtlantic(vector<vector<int>>& matrix) {
		if (matrix.empty() || matrix[0].empty()) {
			return {};
		}
		int m = matrix.size(), n = matrix[0].size();
		vector<vector<bool>>canReachP(m, vector<bool>(n, false));
		vector<vector<bool>>canReachA(m, vector<bool>(n, false));
		for (int i = 0; i < m; ++i) {
			dfs(matrix, canReachP, i, 0);
			dfs(matrix, canReachA, i, n - 1);
		}
		for (int i = 0; i < n; ++i) {
			dfs(matrix, canReachP, 0, i);
			dfs(matrix, canReachA, m - 1, i);
		}
		vector<vector<int>>ans;
		for (int i = 0; i < m; ++i) {
			for (int j = 0; j < n; ++j) {
				if (canReachA[i][j] && canReachP[i][j]) {
					ans.push_back(vector<int>{i, j});
				}
			}
		}
		return ans;
	}
};