class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        for(auto i = nums.begin();i< nums.end() ; i++){
            if(*i == val){
                nums.erase(i);
                i--;
            }
        }
        
        for(auto i=nums.begin();i<nums.end();i++)
            cout<<*i<<" ";
        
        return nums.size();
        
    }
};