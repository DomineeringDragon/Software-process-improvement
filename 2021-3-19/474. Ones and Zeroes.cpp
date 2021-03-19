//dp[i][j]表示i个0 j个1可以构成的最大子集数目，故有状态转移方程
//k表示第k个字符,if(i>=cost0[k],j>=cost1[k]),dp[i][j]=max(1+dp[i-cost0[k][j-cost1[k]],dp[i][j]),可以利用for循环的判断省去IF
//注意需要倒着遍历，可以根据状态转移方程和状态转移图推出
class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<vector<int>> dp(m+1,vector<int>(n+1,0));
        
        for(string str:strs){
            int cost0=0,cost1=0;
            for(char c:str){
                if(c=='0'){
                    cost0++;
                }else{
                    cost1++;
                }
            }
            for(int i=m;i>=cost0;--i){
                for(int j=n;j>=cost1;--j){
                    dp[i][j]=max(dp[i][j],1+dp[i-cost0][j-cost1]);
                }
            }
        }
        return dp[m][n];
    }
};