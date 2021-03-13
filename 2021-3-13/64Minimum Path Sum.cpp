//�ܼ򵥵Ŀ�����״̬ת�Ʒ���Ϊdp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + grid[i][j]��֮���Ǳ߽��������ɡ�
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
/*ѹ���ռ䣺��Ϊdp �����ÿһ��ֵֻ����ߺ������ֵ��أ����ǿ���ʹ�ÿռ�ѹ����dp ����ѹ��Ϊ
һά�����ڵ�i �У��ڱ�������j �е�ʱ����Ϊ��j - 1 ���Ѿ����¹��ˣ�����dp[j - 1] ����dp[i][j - 1]
��ֵ����dp[j] �����£���ǰ�洢��ֵ���ڵ�i - 1 �е�ʱ�����ģ����Դ���dp[i - 1][j] ��ֵ��
����״̬ת�Ʒ��̱�Ϊ��dp[j] = min(dp[j], dp[j - 1]) + grid[i][j],���У�dp[j]����dp[i-1][j]��dp[j-1]����dp[i][j-1]
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