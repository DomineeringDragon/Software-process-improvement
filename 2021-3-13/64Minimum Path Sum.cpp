//很简单的看出，状态转移方程为dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + grid[i][j]，之后考虑边界条件即可。
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, 0));
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (i == 0 && j == 0) {
                    dp[i][j] = grid[i][j];
                }
                else if (i == 0) {
                    dp[i][j] = dp[i][j - 1] + grid[i][j];
                }
                else if (j == 0) {
                    dp[i][j] = dp[i - 1][j] + grid[i][j];
                }
                else {
                    dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + grid[i][j];
                }
            }
        }
        return dp[m - 1][n - 1];
    }
};
/*压缩空间：因为dp 矩阵的每一个值只和左边和上面的值相关，我们可以使用空间压缩将dp 数组压缩为
一维。对于第i 行，在遍历到第j 列的时候，因为第j - 1 列已经更新过了，所以dp[j - 1] 代表dp[i][j - 1]
的值；而dp[j] 待更新，当前存储的值是在第i - 1 行的时候计算的，所以代表dp[i - 1][j] 的值。
所以状态转移方程变为：dp[j] = min(dp[j], dp[j - 1]) + grid[i][j],其中，dp[j]代表dp[i-1][j]，dp[j-1]代表dp[i][j-1]
*/
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<int> dp(n, 0);
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (i == 0 && j == 0) {
                    dp[j] = grid[i][j];
                }
                else if (i == 0) {
                    dp[j] = dp[j - 1] + grid[i][j];
                }
                else if (j == 0) {
                    dp[j] = dp[j] + grid[i][j];
                }
                else {
                    dp[j] = min(dp[j], dp[j - 1]) + grid[i][j];
                }
            }
        }
        return dp[n - 1];
    }
};