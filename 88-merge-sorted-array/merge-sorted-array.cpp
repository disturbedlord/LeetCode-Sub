class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int j = 0, i = 0;
        if(n == 0) return;
        vector<int> res;
        while(i < n && j < m){
            if(nums1[j] <= nums2[i]){
                res.push_back(nums1[j++]);
            }else{
                res.push_back(nums2[i++]);
            }
        }
        while(i < n) res.push_back(nums2[i++]);
        while(j < m) res.push_back(nums1[j++]);

        nums1 = res;
    }
};