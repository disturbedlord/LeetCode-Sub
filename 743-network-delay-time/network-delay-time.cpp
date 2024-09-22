using vec = vector<vector<int>>;
class Node{
    public:
        int u;
        int v;
        int weight;
        Node(int c , int a , int b){
            v = a;
            u = c;
            weight = b;
        }
};
using vec2 = vector<vector<Node>>;
class Solution {
public:
    

    vec2 createAdjacencyList(vec& times , int n){
        vector<vector<Node>> adjList = vector<vector<Node>>(n + 1 , vector<Node>());
        //cout<<adjList[0].size();
        for(auto time : times){
            int u = time[0];
            int v = time[1];
            int w = time[2];
            //cout<<u<<"-"<<v<<"-"<<w<<endl;
            adjList[u].push_back(Node(u , v , w));
        }
        
        // for(auto a : adjList){
        //     for(auto b : a){
        //         cout<<b.u<<" "<<b.v<<" "<<b.weight<<endl;
        //     }
        // }

        return adjList;
    }

    int networkDelayTime(vector<vector<int>>& times, int n, int start) {
        vec2 adjList = createAdjacencyList(times , n);

        vector<int> dist = vector<int>(n + 1 , INT_MAX);

        priority_queue<pair<int,int>> queue;
        queue.push({0 , start});
        dist[start] = 0;
        int res = 0;
        while(!queue.empty()){
            auto u = queue.top();
            queue.pop();
            int weight = u.first;
            for(auto v : adjList[u.second]){
                if(v.weight + weight < dist[v.v]){
                    dist[v.v] = v.weight + weight;
                    queue.push({dist[v.v] , v.v});
                }
            }
        }

        for(int l = 1;l<=n;l++){
            //cout<<dist[l]<<endl;
            if(dist[l] == INT_MAX) {return -1;}
            
            else {
                res = max(res , dist[l]);
            }
        }

        return res;
    }
};