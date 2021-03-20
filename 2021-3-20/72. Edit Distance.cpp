class Solution {
public:
    int minDistance(string word1, string word2) {
        int m = word1.length(), n = word2.length();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        for(int i = 0; i <= m; ++i){
            for(int j = 0; j <= n; ++j){
                if(i==0){
                    dp[i][j]=j;
                }else if(j==0){
                    dp[i][j]=i;
                }else{
                    dp[i][j]=min(dp[i-1][j-1]+((word1[i-1]==word2[j-1])?0:1),min(1+dp[i-1][j],1+dp[i][j-1]));
                    
                }
            }
        }
        return dp[m][n];
    }
};
二维数组dp[i][j]，表示将第一个字符串到位置i 为止，和第
二个字符串到位置j 为止，最多需要几步编辑。当第i 位和第j 位对应的字符相同时，dp[i][j] 等
于dp[i-1][j-1]；当二者对应的字符不同时，修改的消耗是dp[i-1][j-1]+1，插入i 位置/删除j 位置
的消耗是dp[i][j-1] + 1，插入j 位置/删除i 位置的消耗是dp[i-1][j] + 1。