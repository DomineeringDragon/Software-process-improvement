class Solution {
public:
	void dfs(vector<vector<int>>& isConnected, int i, vector<bool>& visited) {

		int m = isConnected.size();
		for (int k = 0; k < m; ++k) {
			if (isConnected[i][k] == 1 && !visited[k]) {
				visited[k] = true;
				dfs(isConnected, k, visited);
			}
		}
	}
	int findCircleNum(vector<vector<int>>& isConnected) {
		int n = isConnected.size();
		vector<bool> visited(n, false);
		int count = 0;
		for (int i = 0; i < n; ++i) {
			if (!visited[i]) {
				dfs(isConnected, i, visited);
				++count;
			}
		}
		return count;
	}
};
// class Solution {
// public:
//     void dfs(vector<vector<int>>& isConnected, vector<int>& visited, int provinces, int i) {
//         for (int j = 0; j < provinces; j++) {
//             if (isConnected[i][j] == 1 && !visited[j]) {
//                 visited[j] = 1;
//                 dfs(isConnected, visited, provinces, j);
//             }
//         }
//     }

//     int findCircleNum(vector<vector<int>>& isConnected) {
//         int provinces = isConnected.size();
//         vector<int> visited(provinces);
//         int circles = 0;
//         for (int i = 0; i < provinces; i++) {
//             if (!visited[i]) {
//                 dfs(isConnected, visited, provinces, i);
//                 circles++;
//             }
//         }
//         return circles;
//     }
// };