class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        if(coins.empty()) return -1;
        vector<int> dp(amount+1,amount+2);//dp[i]表示构成i需要的最小硬币数目,初始化为amout+2,那是无法达到的值
        dp[0]=0;
        for(int i=1;i<=amount;++i){
            for(int coin:coins){
                if(i>=coin){
                    dp[i] = min(dp[i], dp[i-coin] + 1);
                }
            }
        }
        return dp[amount] == amount + 2? -1: dp[amount];//有可能最后还是无法完成,故比较是否为amout+2,是的话返回-1
    }
};