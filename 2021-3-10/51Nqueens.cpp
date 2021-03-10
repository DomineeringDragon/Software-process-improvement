//class Solution {
//public:
//	vector<vector<string>>ans;
//	bool Valid(vector<string>& map, int n, int row, int column) {
//		for (int i = 0; i < row; i++) {
//			if (map[i][column] == 'Q') {
//				return false;
//			}
//		}
//		for (int i = row - 1, j = column - 1; i >= 0 && j >= 0; i--, j--) {
//			if (map[i][j] == 'Q') {
//				return false;
//			}
//		}
//		for (int i = row - 1, j = column + 1; i >= 0 && j < n; i--, j++) {
//			if (map[i][j] == 'Q') {
//				return false;
//			}
//		}
//		return true;
//	}
//	void backtracking(vector<string>& map, int n, int row) {
//		if (n == row) {
//			ans.push_back(map);
//			return;
//		}
//		for (int i = 0; i < n; i++) {
//			if (Valid(map, n, row, i)) {
//				map[row][i] = 'Q';
//				backtracking(map, n, row + 1);
//				map[row][i] = '.';
//			}
//		}
//		return;
//	}
//
//
//	vector<vector<string>> solveNQueens(int n) {
//		vector<string> map(n, string(n, '.'));
//		backtracking(map, n, 0);
//		return ans;
//	}
//};