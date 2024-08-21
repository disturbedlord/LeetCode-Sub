class Solution {
public:
    int RES;

    void solve(int curr , int copy , int cnt , int n){
        if(curr > n) return;
        
        if(curr == n){
            RES = min(RES , cnt);
        }
        
        // Add Copied Data
        solve(curr + copy , copy , cnt + 1 , n); //PASTE ONCE
        //Copy All
        solve(curr + curr , curr , cnt + 2 , n);
    }

    int minSteps(int n) {
        if(n == 1)return 0;
        RES = n;
        solve(1 , 1 , 1 , n);
        return RES;
    }
};