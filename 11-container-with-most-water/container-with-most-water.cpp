class Solution {
public:
    int maxArea(vector<int>& height) {
        int nn = height.size();
        int res = 0;

        int left = 0 , right = nn - 1;
        
        while(left < right){
            res = max(res , abs(left - right) * min(height[left] , height[right]));
            if(height[left] < height[right]){
                left++;
            }else right--;
        }

        return res;
    }
};