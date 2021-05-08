class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int count=0,psum=0;
        unordered_map<int,int> hash;
        hash[0]=1;
        for(int i:nums){
            psum+=i;
            count+=hash[psum-k];
            ++hash[psum];
        }
        return count;
    }
};