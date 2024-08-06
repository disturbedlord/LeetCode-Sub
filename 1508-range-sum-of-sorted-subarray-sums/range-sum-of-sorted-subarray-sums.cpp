typedef priority_queue<pair<int,int>> p;
#define MOD 1000000007
class Solution {
public:
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        p pq;
        for(int i=0;i<n;i++)pq.push({-nums[i] % MOD , i}); 
        //cout<<-nums[i]<<" : "<<i<<endl;}
        int res = 0;
        int idx = 1;
        while(idx <= right && !pq.empty()){
            auto top = pq.top();
            pq.pop();
            //cout<<top.first<<endl;
            if(idx >= left){
                res += -top.first;
                res %= MOD;
            }

            if(top.second + 1 < n){
                auto next = -top.first + nums[top.second + 1];
                pq.push({-next , top.second + 1});
                //cout<<"NEXR : "<<next<<endl;
            }
            idx ++;
        }

        return res;
    }
};