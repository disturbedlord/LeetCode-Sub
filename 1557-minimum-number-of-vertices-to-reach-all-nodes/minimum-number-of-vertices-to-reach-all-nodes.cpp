typedef vector<vector<int>> llist;
class Solution {
public:

    llist createAdjacencyllist(int n , vector<vector<int>>& edges){
        llist adjllist = llist(n , vector<int>());
        for(auto edge : edges){
            int u = edge[0];
            int v = edge[1];
            adjllist[u].push_back(v);
        }
        // int i = 0;
        // for(auto l : adjllist){
        //     cout<<i<<"->";
        //     for(auto j : l){
        //         cout<<j<<" ";
        //     }
        //     cout<<endl;
        //     i++;
        // }
        return adjllist;
    }

    void dfs(int node , vector<int>& visited , llist& adjllist){
        if(visited[node]) return;
        for(auto next: adjllist[node]){
            if(!visited[next]){
                dfs(next , visited , adjllist);
                visited[next] = 1;
            }
        }
    }

    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        auto adjllist = createAdjacencyllist(n  , edges);
        vector<int> visited = vector<int>(n , 0);

        for(int i=0;i<n;i++){
            if(!visited[i]){
                dfs(i , visited , adjllist);
            }
        }
        vector<int> res = vector<int>();
        for(int i=0;i<n;i++){
            if(!visited[i]) res.push_back(i);
        }
        return res;
    }
};