class Solution {

private:
	vector<int> candidates;
	vector<vector<int>> res;
	vector<int> path;
public:
	void DFS(int start, int target) {
		if (target == 0) {
			res.push_back(path);
			return;
		}

		for (int i = start; i < candidates.size() && target - candidates[i] >= 0; i++) {
			//如果为相同的元素则进入下一次循环，防止同样值的元素在答案数组中处于同一个下标
			if (i > start&& candidates[i] == candidates[i - 1])
				continue;
			path.push_back(candidates[i]);
			DFS(i + 1, target - candidates[i]);
			path.pop_back();
		}
	}

	vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
		sort(candidates.begin(), candidates.end());
		this->candidates = candidates;
		DFS(0, target);
		return res;
	}
};

