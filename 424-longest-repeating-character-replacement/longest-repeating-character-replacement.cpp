class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size();
        unordered_map<char,int> mp;
        int left = 0;
        int right = 0;
        int maxF = 0;
        int res = 0;
        while(right < n){
            mp[s[right]]++;
            maxF = max(maxF , mp[s[right]]);
            
            int rep = right - left + 1 - maxF;

            while(rep > k){
                mp[s[left]]--;
                left++;
                maxF = 0;
                for(auto x : mp){
                    maxF = max(x.second , maxF);
                }
                rep = right - left + 1 - maxF;
            }
            res = max(res , right - left + 1);
            right++;
        }
        return res;
    }
};