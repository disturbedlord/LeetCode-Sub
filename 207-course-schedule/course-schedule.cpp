class Solution {
public:
    bool res = false;
    vector<vector<int>> adj;
    int END;
    vector<int> seen;
    bool findLoop(int idx){
        if(seen[idx] == 2) return false;
        if(seen[idx] == 1){return true;}
        seen[idx] = 1;
        for(auto next : adj[idx]){
            if(adj[next].size() != 0 && findLoop(next))
                return true;
        }
        seen[idx] = 2;
        return false;
    }

    void createAdjacencyMatrix(int n , vector<vector<int>>& mat){
        adj = vector<vector<int>>(n);
        for(auto m : mat){
            adj[m[1]].push_back(m[0]);
        }
        int i = 0;
        // for(auto x : adj){
        //     cout<<i++<<" -> ";
        //     for(auto y : x){
        //         cout<<y<<" ";
        //     }
        //     cout<<endl;
        // }
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        adj.clear();
        END = numCourses - 1;
        createAdjacencyMatrix(numCourses , prerequisites);
        seen = vector<int>(END + 1 , 0);
        for(int i=0;i<numCourses;i++){
            // for(auto ele : seen){
            //     cout<<ele<<" ";
                
            // }
            // cout<<endl;
            if(seen[i] != 2 && adj[i].size() != 0 && findLoop(i)){return false;}
            // seen[i] = 2;
        }
        return true;
    }
};