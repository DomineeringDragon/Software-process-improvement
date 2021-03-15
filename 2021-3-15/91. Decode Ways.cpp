class Solution {
public:
    int numDecodings(string s) {
        int n=s.length();
        if(n==0){
            return 0;
        }
        int prev =s[0]-'0';
        if(!prev)return 0;
        if(n==1)return 1;
        vector<int> dp(n+1,1);
        for(int i=2;i<=n;++i){
            int cur =s[i-1]-'0';
            if(cur==0&&(prev==0||prev>2)){//如果当前字符为0，而前面的不是1或2，那么就构不成新的解码，return 0
                return 0;
            }
            if((prev>0&&prev<2)||(prev==2&&cur<7)){//prev和cur构成的数字在10到26间
                if(cur){//如果cur不为0，那么就有2种解码方式，即cur和prev放开译码、合并译码，分别对应dp[i-1]和dp[i-2]
                    dp[i]=dp[i-1]+dp[i-2];
                }else{//如果cur为0，那么必须和前面的prev合并译码，为dp[i-2]
                    dp[i]=dp[i-2];
                }
            }else{//如果cur是大于等于7的值，那么不能和prev合并译码，或者prev大于2，也不能和cur合并译码
                dp[i]=dp[i-1];
            }
            prev=cur;
        }
        return dp[n];
    }
};

//leetcode的简单直观思路

class Solution {
public:
    int numDecodings(string s) {
        int n=s.size();
        if(n==0){
            return 0;
        }
        int prev =s[0]-'0';
        if(!prev)return 0;
        if(n==1)return 1;
        vector<int> dp(n+1);
        dp[0]=1;dp[1]=1;
        for(int i=1;i<n;++i){
            if(s[i]=='0'){
                if(s[i-1]=='1'||s[i-1]=='2'){
                    dp[i+1]=dp[i-1];
                }else{
                    return 0;
                }
            }else {
                if(s[i-1]=='1'||(s[i-1]=='2'&&s[i]<='6')){
                    dp[i+1]=dp[i]+dp[i-1];
                }else{
                    dp[i+1]=dp[i];
                }
            }
        }
        return dp[n];
    }
};