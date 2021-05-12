class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> s;
        for(int x:nums){
            if(s.find(x)!=s.end()){//find方法找到的话，则返回对应位置，没找到的话，返回最后一个元素的位置
                return true;
            }
            s.insert(x);
        }
        return false;
    }
};