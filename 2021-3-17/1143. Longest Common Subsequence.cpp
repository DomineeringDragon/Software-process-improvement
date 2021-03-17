class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int m=text1.size();
        int n=text2.size();
        vector<vector<int>>dp(m+1,vector<int>(n+1,0));//dp[i][j]代表text1在i位置，text2在j位置时，最大的公共子串长度
        for(int i=1;i<=m;++i){
            for(int j=1;j<=n;++j){
                if(text1[i-1]==text2[j-1]){//如果两个字符相等，那么显然，dp[i][j]为dp[i-1][j-1]加1
                    dp[i][j]=dp[i-1][j-1]+1;
                }else{
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);//若当前字符不同，我们只需要把第一个字符串往前退一个字符或者第二个字符串往前退一个字符然后记录最大值即可(相当于看 text1[0, i - 2] 与 text2[0, j - 1] 的最长公共子序列 和 text1[0, i - 1] 与 text2[0, j - 2] 的最长公共子序列，取最大的)
                }
            }
        }
        return dp[m][n];
    }
};