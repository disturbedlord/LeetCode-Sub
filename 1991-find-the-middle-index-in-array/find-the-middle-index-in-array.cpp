class Solution {
public:
    int findMiddleIndex(vector<int>& nums) {
        vector<int> left , right;
        int a = 0;
        for(auto n : nums){
            left.push_back(a);
            a += n;
        }

        a = 0;
        for(int i=nums.size() - 1;i>=0;i--){
            right.push_back(a);
            a += nums[i];
        }
        // for(auto x : left) cout<<x<<" ";
        // cout<<endl;
        // for(auto x : right) cout<<x<<" ";
        for(int i=0;i<nums.size();i++){
            if(left[i] == right[nums.size() - 1 - i]) return i;
        }
        return -1;
    }
};