class Solution {
public:
    vector<vector<int>> res;

    void dfs(vector<vector<int>>& g , int target , vector<int> path , int i){
        if(i >= g.size()) return;
        path.push_back(i);
        if(i == target) {res.push_back(path) ; return;}
        for(auto next : g[i]){
            dfs(g , target , path , next);
        }
    }

    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        res.clear();
        if(graph.size() == 0) return {};
        for(auto edge : graph[0])
            dfs(graph , graph.size() - 1 , {0} , edge);
        return res;
    }
};