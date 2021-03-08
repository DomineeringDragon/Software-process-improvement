class Solution {
public:
	void backtracking(int i, int j, vector<vector<char>>& board, vector<vector<bool>>& visited, bool& find, string& word, int pos) {
		if (i >= board.size() || i < 0 || j >= board[0].size() || j < 0) {
			return;
		}
		if (find || visited[i][j] || word[pos] != board[i][j]) {
			return;
		}
		if (pos == word.size() - 1) {
			find = true;
			return;
		}
		visited[i][j] = true;
		backtracking(i + 1, j, board, visited, find, word, pos + 1);
		backtracking(i - 1, j, board, visited, find, word, pos + 1);
		backtracking(i, j + 1, board, visited, find, word, pos + 1);
		backtracking(i, j - 1, board, visited, find, word, pos + 1);
		visited[i][j] = false;
	}
	bool exist(vector<vector<char>>& board, string word) {
		if (board.empty())return false;
		int m = board.size(), n = board[0].size();
		bool find = false;
		vector<vector<bool>> visited(m, vector<bool>(n, false));
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				backtracking(i, j, board, visited, find, word, 0);
			}
		}
		return find;
	}
};