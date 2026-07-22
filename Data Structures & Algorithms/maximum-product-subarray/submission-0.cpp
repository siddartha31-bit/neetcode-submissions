class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int res=nums[0];
        int mini=nums[0];
        int maxi=nums[0];
        for(int i=1;i<nums.size();i++){
            int curr=nums[i];
            if(curr<0){
                swap(mini,maxi);
            }
            mini=min(curr,curr*mini);
            maxi=max(curr,curr*maxi);
            res=max(res,maxi);
        }return res;
    }
};