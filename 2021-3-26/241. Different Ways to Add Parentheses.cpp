class Solution {
public:
    vector<int> diffWaysToCompute(string expression) {
        vector<int> ways;
        int n=expression.size();
        for(int i=0;i<n;++i){
            char c=expression[i];
            if(c=='+'||c=='-'||c=='*'){
                vector<int> left=diffWaysToCompute(expression.substr(0,i));
                vector<int> right=diffWaysToCompute(expression.substr(i+1));
                for(const int & l:left){
                    for(const int & r:right){
                        if(c=='+'){
                            ways.push_back(l+r);

                        }else if(c=='*'){
                            ways.push_back(l*r);

                        }else if(c=='-'){
                            ways.push_back(l-r);

                        }
                    }
                }
            }
        }
        if (ways.empty()) ways.push_back(stoi(expression));
        return ways;
    }
};
//分治法