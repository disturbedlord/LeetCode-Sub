class Solution {
public:
    //TC : O(v + e)
    //SC : O(V)
    int dfs(vector<vector<int>>& graph , vector<int>& visited , int node){
        
        if(visited[node]) return visited[node];
        visited[node] = 1;

        if(graph[node].size() == 0){
            visited[node] = 2;
            return 2;
        }else{
            int safe = 0;
            for(auto next : graph[node]){
                if(dfs(graph , visited , next) == 2) safe++;
            }

            if(safe == graph[node].size()) {visited[node] = 2;return 2;}
        }

        return 1;
    }

    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> visited = vector<int>(n , 0);

        vector<int> res = vector<int>();
        for(int i=0;i<n;i++){
            if(!visited[i]){
                dfs(graph , visited , i);
            }
        }
        
        for(int i=0;i<n;i++){if(visited[i] == 2) res.push_back(i);}
        return res;
    }
};