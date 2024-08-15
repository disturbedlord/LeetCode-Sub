#include<string>

class Solution {
public:
    bool isPalindrome(int x) {
        string num;
        num = to_string(x);
        
        int flag = 0;
        int n = num.length();
        for(int i=0;i<n;i++){
            if(num[i] == num[n - i - 1]){
                
            }else{
                flag = 1;
                break;
            }
        }
        
        if(flag == 1)
            return 0;
        else
            return 1;
        
        
     
    }
};