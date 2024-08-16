class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();
        int res = 0;
        int idx = 0;
        int start = 0;
        while(idx < n){
            if(nums[idx] == 1){
                idx ++;
            }else{
                if(k > 0){ k--; idx++;}
                else{
                    while(nums[start] == 1) start++;
                    if(nums[start] == 0) {k++;start++;}
                }
            }
            res = max(res , idx - start);
        }
        return res;
    }
};