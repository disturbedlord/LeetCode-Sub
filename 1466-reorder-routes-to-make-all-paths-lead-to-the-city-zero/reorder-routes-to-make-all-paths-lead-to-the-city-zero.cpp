typedef vector<vector<int>> l;
class Solution {
public:

    l* createAdj(int n , l& conn){
        l* adjList = new l(n + 1, vector<int>());
        for(auto c : conn){
            int u = c[0] + 1;
            int v = c[1] + 1;
            (*adjList)[u].push_back(v);
            (*adjList)[v].push_back(-u);
        }
        // int i = 0;
        // for(auto itr : *adjList){
        //     cout<<i<<"=>";
        //     for(auto y : itr){
        //         cout<<y<<" ";
        //     }
        //     cout<<endl;
        //     i++;
        // }
        return adjList;
    }
    int x = 0;
    bool dfs(vector<int>& visited , int curr , l& adjList , int prev){
        // for(auto v : visited) cout<<v<<"-";
        // cout<<endl;
        // cout<<curr<<" : "<<prev<<endl;
        if(visited[curr]) return visited[curr];
        for(auto next : adjList[curr]){
            int ori = abs(next);
            if(ori != prev){
                if(visited[ori]) {                    x += next < 0 ? 1 : 0;visited[curr] = 1;
return 1;}
                if(dfs(visited , ori , adjList , curr)){
                    x += next < 0 ? 1 : 0;
                    visited[curr] = 1;
                    return 1;
                }
            }
        }

        return false;
    }

    int minReorder(int n, vector<vector<int>>& connections) {
        l* adjList = createAdj(n , connections);
        int res = 0;
        vector<int>* visited = new vector<int>(n + 1 , 0);
        (*visited)[1] = 1;
        x = 0;
        for(int i=1;i<n + 1;i++){
            if(!(*visited)[i]){ 
                if(dfs(*visited , i , *adjList , 0)){
                    (*visited)[i] = 1;
                }
            }
        }

        return x;
    }
};