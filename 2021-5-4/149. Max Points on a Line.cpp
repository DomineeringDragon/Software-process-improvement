class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        unordered_map<double,int> hash;
        int max_count = 0, same = 1, same_y = 1;
        for(int i=0;i<points.size();++i){
            
            same=1,same_y=1;
            for(int j=i+1;j<points.size();++j){
                if(points[i][1]==points[j][1]){
                    same_y++;
                    if(points[i][0]==points[j][0]){
                    same++;//考虑同一个位置的特殊情况
                    }
                }else {
                    double dx=points[i][0]-points[j][0],dy=points[i][1]-points[j][1];
                    ++hash[dx/dy];
                }
            }
            max_count = max(max_count, same_y);//首先记录没有斜率的点
            for (auto item : hash) {//比较即可，注意同一个位置要加上去
                max_count = max(max_count, same + item.second);
            }
            hash.clear();
        }
        return max_count;
    }
};