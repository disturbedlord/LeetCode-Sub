class Solution {
public:
    vector<vector<int>>res;
    void solve(vector<int>& c , int t , int i , vector<int> arr , int& n){
        
        if(i >= n || t < 0) return;

        if(t == 0){
            res.push_back(arr);
        }

        for(;i<n;i++){
            if(t - c[i] < 0) return;
            arr.push_back(c[i]);
            solve(c , t - c[i] , i , arr , n);
            arr.pop_back();
        }
        // solve(c , t , i + 1 , arr , n);
    }

    vector<vector<int>> combinationSum(vector<int>& c, int target) {
        int n = c.size();
        sort(c.begin() , c.end());
        solve(c , target , 0 , {} , n);
        return res;
    }
};