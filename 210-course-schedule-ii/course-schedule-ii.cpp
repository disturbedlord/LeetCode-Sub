class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& pre) {
        vector<int> inDegree = vector<int>(numCourses , 0);
        vector<vector<int>> adjList = vector<vector<int>>(numCourses , vector<int>());
        
        for(auto ele : pre){
            adjList[ele[1]].push_back(ele[0]);
            inDegree[ele[0]]++;
        }

        queue<int> q;
        for(int i=0;i< inDegree.size();i++){
            if(inDegree[i] == 0) q.push(i);
        }
        vector<int> res = vector<int>();

        while(!q.empty()){
            auto front = q.front();
            q.pop();

            res.push_back(front);

            for(auto next : adjList[front]){
                inDegree[next]--;
                if(inDegree[next] == 0) q.push(next);
            }
        }

        return res.size() == numCourses ? res : vector<int>();
    }
};