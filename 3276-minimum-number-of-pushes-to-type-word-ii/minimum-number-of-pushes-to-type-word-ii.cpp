class Solution {
public:
    int minimumPushes(string word) {
        cin.sync_with_stdio(0); cin.tie(0); cout.tie(0);

        unordered_map<char,int> mp = unordered_map<char, int>();

        for(auto c : word) mp[c]++;

        priority_queue<int> pq = priority_queue<int>();
        for(auto kv : mp){
            pq.push(kv.second);
        }

        int res = 0;
        int idx = 0;
        int cnt = 0;
        int press = 1;

        while(!pq.empty()){
            auto top = pq.top();pq.pop();
            res = res + press * top;
            cnt ++;
            press = (cnt / 8) + 1;
        }

        return res;
    }
};