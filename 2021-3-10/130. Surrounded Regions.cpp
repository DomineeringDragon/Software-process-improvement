//class Solution {
//public:
//	void dfs(vector<vector<char>>& board, int x, int y, int m, int n) {
//		if (x < 0 || x >= m || y < 0 || y >= n || board[x][y] != 'O') {
//			return;
//		}
//		board[x][y] = 'A';
//		dfs(board, x + 1, y, m, n);
//		dfs(board, x - 1, y, m, n);
//		dfs(board, x, y + 1, m, n);
//		dfs(board, x, y - 1, m, n);
//
//	}
//	void solve(vector<vector<char>>& board) {
//		if (board.empty())return;
//		int m = board.size(), n = board[0].size();
//		for (int i = 0; i < m; ++i) {
//			dfs(board, i, 0, m, n);
//			dfs(board, i, n - 1, m, n);
//		}
//		for (int j = 0; j < n; ++j) {
//			dfs(board, 0, j, m, n);
//			dfs(board, m - 1, j, m, n);
//		}
//		for (int i = 0; i < m; ++i) {
//			for (int j = 0; j < n; ++j) {
//				if (board[i][j] == 'A') {
//					board[i][j] = 'O';
//				}
//				else if (board[i][j] == 'O') {
//					board[i][j] = 'X';
//				}
//			}
//		}
//	}
//};