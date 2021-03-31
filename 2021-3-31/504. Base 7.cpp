class Solution {
public:
    string convertToBase7(int num) {
        if(num==0){return "0";}
        bool is_negative=(num<0);
        if(is_negative)num=-num;
        string Snum;
        while(num){
            int a = num / 7, b = num % 7;
            Snum = to_string(b) + Snum;
            num = a;
        }
        return is_negative? "-" + Snum: Snum;
    }
};