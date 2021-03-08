class Solution {
public:
	void backtracking(int n, int k, int level, int count, vector<int>& record, vector<vector<int>>& ans) {
		if (count == k) {
			ans.push_back(record);
			return;
		}
		for (int i = level; i <= n; ++i) {
			record[count++] = i;
			backtracking(n, k, i + 1, count, record, ans);
			--count;
		}
	}
	vector<vector<int>> combine(int n, int k) {
		vector<vector<int>>ans;
		vector<int> record(k, 0);
		int count = 0;
		int level = 1;
		backtracking(n, k, level, count, record, ans);
		return ans;
	}
};