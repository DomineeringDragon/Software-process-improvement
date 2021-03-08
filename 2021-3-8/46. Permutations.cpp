class Solution {
public:
	void backTracking(vector<int>& nums, vector<vector<int>>& ans, int
		level) {
		int m = nums.size();
		if (level == m - 1) {
			ans.push_back(nums);
			return;
		}
		for (int i = level; i < m; ++i) {
			swap(nums[i], nums[level]);
			backTracking(nums, ans, level + 1);
			swap(nums[i], nums[level]);
		}
	}
	vector<vector<int>> permute(vector<int>& nums) {
		vector<vector<int>>ans;
		backTracking(nums, ans, 0);
		return ans;
	}
};