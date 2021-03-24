class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n= prices.size();
        if(n<2) return 0;
        vector<vector<int>> dp(n,vector<int>(2,0));
        dp[0][0]=0;
        dp[0][1]=-prices[0];
        for(int i=1;i<n;++i){
            dp[i][0]=max(dp[i-1][0],dp[i-1][1]+prices[i]);
            dp[i][1]=max(dp[i-1][1],-prices[i]);
        }
        return dp[n-1][0];
    }
};
//dp[i][j]下标为 i 这一天结束的时候，手上持股状态为 j 时，我们持有的现金数。j = 0，表示当前不持股；j = 1，表示当前持股。
/*dp[i][0]：规定了今天不持股，有以下两种情况：昨天不持股，今天什么都不做；昨天持股，今天卖出股票（现金数增加），
dp[i][1]：规定了今天持股，有以下两种情况：昨天持股，今天什么都不做（现金数与昨天一样）；昨天不持股，今天买入股票（注意：只允许交易一次，因此手上的现金数就是当天的股价的相反数）。*/

