class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        unordered_map<char,int> mp;
        int res = 0;
        
        for(int i=0 , j = 0;i<n;i++){
            if(mp.find(s[i]) != mp.end()){
                j = max(mp[s[i]] + 1 , j);
            }
            
            mp[s[i]] = i;
            res = max(res , i - j + 1);
            
        }
        
        return res;
    }
};