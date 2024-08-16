class Solution {
public:
    //SC : O(1)
    //TC : O()
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();
        int res = 0;
        int idx = 0;
        int start = 0;
        //O(n + n) ~ O(n)
        while(idx < n){ //O(n)
            if(nums[idx] == 1){
                idx ++;
            }else{
                if(k > 0){ k--; idx++;}
                else{
                    
                    while(k <= 0) { if(nums[start] == 0) k++; start++;} // O(n)
                    //We Have a 0 here
                }
            }
            res = max(res , idx - start);
        }
        return res;
    }
};