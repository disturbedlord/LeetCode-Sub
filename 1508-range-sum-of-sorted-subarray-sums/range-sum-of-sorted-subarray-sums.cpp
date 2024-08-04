typedef priority_queue<long long int> pqueue;
#define MOD (1000000007);
class Solution {
public:
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        pqueue pq;

        for(int i=0;i<n;i++){
            long long int sum = 0;
            for(int j=i;j<n;j++){
                sum += nums[j];
                sum %= MOD;
                //if(i == 0){
                //cout<<nums[j]<<" - "<<(1000000007)<<endl;
                //cout<<"S : "<<sum<<" : "<< -sum<<endl;
                //}
                pq.push(-sum);
            }
        }

        long long int res = 0;
        int idx = 1;
        //cout<<pq.size()<<endl;
        while(!pq.empty()){
            //cout<<pq.top()<<endl;
            if(idx >= left && idx <= right){
                res += -pq.top();
                res %= MOD;
                //cout<<res<<endl;
            }
            pq.pop();
            idx ++;
        }

        //cout<<idx<<endl;

        return res;
    }
};