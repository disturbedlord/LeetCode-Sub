class Solution {
public:

    vector<vector<int>> res;
    set<vector<int>> seen;

    void knapSack(vector<int>& cand , int& n , int i ,int target , vector<int> comb){
        // for(auto e : comb)cout<<e<<" ";
        // cout<<endl;
        if(target == 0){ 
            if(!seen.count(comb)){
                res.push_back(comb);
                seen.insert(comb);
            }
            return;
        };

        if(i >= n || target < 0 || cand[i] > target)  return;
        int prev = -1;
        for(;i<n;i++){
            if(target - cand[i] < 0) return;
            if(prev == cand[i]) continue;
            comb.push_back(cand[i]);
            knapSack(cand , n , i + 1 , target - cand[i] , comb);
            comb.pop_back();
            prev = cand[i];
        }
        //knapSack(cand , n , i + 1 , target , comb);
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        int n = candidates.size();
        sort(candidates.begin() , candidates.end());
        int total = accumulate(candidates.begin() , candidates.end() , 0);
        if(total < target) return {};
        knapSack(candidates , n , 0 , target , {});
        
        // vector<int> comb;
        // for(int i=0;i<n;i++){
        //     int sum = 0;
        //     for(int j=0;j<n;j++){
        //         sum += candidates[j];z  `
        //         if(candidates[j] > prev)break;

        //     }
        // }

        return res;
    }
};