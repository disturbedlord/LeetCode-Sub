class Solution {
public:
    bool isValid(string s) {
        stack<char> stk;
        unordered_map<char,char> mapping = {{'(' , ')'} , {'[',']'} , {'{' , '}'}};
        for(auto c : s){
            if(!stk.empty() && mapping[stk.top()] == c){
                stk.pop();
            }else{
                stk.push(c);
            }
        }
        
        return stk.size() == 0;
    }
};