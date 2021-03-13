class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        if(matrix.empty()||matrix[0].empty()){
            return 0;
        }
        int m=matrix.size();
        int n=matrix[0].size();
        int max_side=0;
        //dp数组共n+1位，第0位无用，这是为了后面计算的方便，不用考虑初始情况
        vector<vector<int>>dp(m+1,vector<int>(n+1,0));
        //注意构造状态转移方程：dp[i][j]表示以(i, j) 为右下角的全由1 构成的最大正方形的边长。从左上开始往右下遍历，某个点若是1，则需要比较它左、左上、上3个点，取最小值加1，构成新的边长
        for(int i=1;i<=m;++i){
            for(int j=1;j<=n;++j){
                if(matrix[i-1][j-1]=='1'){
                    dp[i][j]=min(dp[i-1][j-1],min(dp[i-1][j],dp[i][j-1]))+1;
                }
                max_side=max(max_side,dp[i][j]);
            }
        }
        return max_side*max_side;
    }
};