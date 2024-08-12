class KthLargest {
public:

    priority_queue<int> pq;
    int K = 0;
    KthLargest(int k, vector<int>& nums) {
        int n = nums.size();
        if(n != 0){
            sort(nums.begin() , nums.end());
            for(int i= n - 1; i>= n - k;i--){
                if(i < 0) break;
                pq.push(-nums[i]);
            }
        }
        K = k;
        //cout<<"SIZE : " << pq.size();
    }
    
    int add(int val) {
        if(!pq.empty() && pq.size() == K && -pq.top() > val){ 
            
            return -pq.top();
        }
        else{
            //cout<<val<<" ";
            pq.push(-val);
            if(pq.size() > K)
                pq.pop();
            return pq.top() == 0 ? 0 : -pq.top();            
        }
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */