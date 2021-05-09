class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        if(mat.empty())return mat;
        int a=mat.size(),b=mat[0].size();
        if(r*c!=a*b) return mat;
        vector<vector<int>> ans;
        vector<int> row;
        for(int i=0;i<a;++i){
            for(int j=0;j<b;++j){
                row.push_back(mat[i][j]);
                if(row.size()==c){
                    ans.push_back(row);
                    row.clear();
                }
            }
        }
        return ans;
    }
};


// 巧妙的解法：
class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& nums, int r, int c) {
        int m = nums.size();
        int n = nums[0].size();
        if (m * n != r * c) {
            return nums;
        }

        vector<vector<int>> ans(r, vector<int>(c));
        for (int x = 0; x < m * n; ++x) {
            ans[x / c][x % c] = nums[x / n][x % n];
        }
        return ans;
    }
};

作者：LeetCode-Solution
链接：https://leetcode-cn.com/problems/reshape-the-matrix/solution/zhong-su-ju-zhen-by-leetcode-solution-gt0g/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。