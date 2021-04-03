class Solution {
public:
    string addStrings(string num1, string num2) {
        int len1=num1.size(),len2=num2.size();
        if(len1 <=len2){
            swap(len1,len2);
            swap(num1,num2);
        }
        reverse(num1.begin(),num1.end());
        reverse(num2.begin(),num2.end());
        int carryBit=0;
        string ans("");
        for(int i=0;i<len2;++i){
            int add = (num1[i]-'0')+(num2[i]-'0')+carryBit;
            if(add >=10){
                carryBit=1;
            }else{
                carryBit=0;
            }
            ans+=to_string(add%10);
        }
        for(int i=len2;i<len1;++i){
            int add=num1[i]-'0'+carryBit;
            if(add >=10){
                carryBit=1;
            }else{
                carryBit=0;
            }
            ans+=to_string(add%10);            
        }
        if(carryBit){
            ans+="1";
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};