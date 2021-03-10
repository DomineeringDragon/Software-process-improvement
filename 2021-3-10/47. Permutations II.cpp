#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
	vector<bool> visited;

	vector<vector<int>> permuteUnique(vector<int>& nums) {
		vector<vector<int>> ansSet;
		vector<int> ans;
		visited.resize(nums.size());
		sort(nums.begin(), nums.end());
		backtrack(nums, ansSet, 0, ans);
		return ansSet;
	}

	void backtrack(vector<int>& nums, vector<vector<int>>& ansSet, int level, vector<int>& ans) {
		//遍历结束将一种答案放入ansSet
		if (level == nums.size()) {
			ansSet.emplace_back(ans);
			return;
		}
		for (int i = 0; i < (int)nums.size(); ++i) {
			//如果遍历过则跳过这次
			if (visited[i]) {
				continue;
			}
			//如果是和前面重复的值，那么用重复值的最后一个来填充level位置，以此去除重复情况
			if (i > 0 && nums[i] == nums[i - 1] && !visited[i - 1]) {
				continue;
			}

			ans.emplace_back(nums[i]);
			visited[i] = true;
			backtrack(nums, ansSet, level + 1, ans);
			visited[i] = false;
			ans.pop_back();

		}
	}
};

int main() {
	Solution solution;
	vector<int> nums{ 1,1,3 };
	vector<vector<int>>ansSet = solution.permuteUnique(nums);
	vector<vector<int>>::iterator i;
	/*for (int i = 0; i < ansSet.size; ++i) {
		cout << endl;
		for (int j = 0; j < ansSet[i].size(); ++j) {
			cout << ansSet[i][j] << " ";
		}
	}*/
	cout << ansSet[0][1];
	return 0;
}