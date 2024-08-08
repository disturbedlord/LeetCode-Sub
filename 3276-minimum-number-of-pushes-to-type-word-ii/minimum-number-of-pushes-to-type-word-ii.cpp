class Solution {
public:
    int minimumPushes(string word) {
        vector<int> memo = vector<int>(26 , 0);

        for(auto c : word) memo[c - 97] ++;
        priority_queue<pair<int , char>> pq = priority_queue<pair<int,char>>();
        for(int v=0;v<26;v++){
            if(memo[v] != 0) pq.push({memo[v] , char(97 + v)});
        }

        int res = 0;
        int idx = 0;
        int cnt = 0;
        int press = 1;
        while(!pq.empty()){
            auto top = pq.top();pq.pop();
            res = res + press * top.first;
            cnt ++;
            press = (cnt / 8) + 1;
        }

        return res;
    }
};