class Solution {
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& g) {
        int n = g.size();
        if(0 == n) return {};

        queue<pair<int , vector<int>>> queue;
        queue.push({0 , {0}});
        vector<vector<int>> res;
        while(!queue.empty()){
            auto front = queue.front();
            queue.pop();
            if(front.first == n - 1){
                res.push_back(front.second);
                continue;
            }
            for(auto next : g[front.first]){
                auto path = front.second;
                path.push_back(next);
                queue.push({next , path});
                path.pop_back(); 
            }
        }
        return res;
    }
};