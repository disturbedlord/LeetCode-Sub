class Solution {
public:
    //TC : O(n)
    //SC : O(1)
    int maxArea(vector<int>& height) {
        int n = height.size();
        if(n <= 1) return 0;
        int l = 0 , r = n - 1;

        int res = 0;
        while(l < r){
            int m = min(height[l] , height[r]);
            //cout<<m<<endl;
            res = max(res , m * (r - l));
            if(height[l] <= height[r]) l++;
            else r--;
        }

        return res;
    }
};