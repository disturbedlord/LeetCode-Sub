class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        unordered_map<string , int> mp = unordered_map<string,int>();
        int n = arr.size();
        string res = "";

        for(auto str : arr){
            mp[str] ++;
        }

        for(auto ele : arr){
            //cout<<ele<<endl;
            if(mp[ele] == 1){
                k --;
            }

            if(k == 0) return ele;
        }


        return res;
    }
};