//±©Á¦·¨
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> v;
        int start=-1;
        int end=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==target&&start==-1){
                start=i;
                end=i;
                v.push_back(start);
            }
            else if(nums[i]==target){end++;}            
        }
        
        if(v.empty()){
            v.push_back(-1);
            v.push_back(-1);
            return v;
        }
        else{v.push_back(end);
            return v;}
    }
};
//