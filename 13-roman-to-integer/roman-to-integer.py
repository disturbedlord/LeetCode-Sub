class Solution:
    def romanToInt(self, s: str) -> int:
        val = 0
        
        rule = {"V" : "I" , "X" : "I" , "L" : "X" , "C" : "X" , "D" : "C" , "M" :
                "C"}
        
        num = {"I" : 1 , "V" : 5 , "X" : 10 , "L" : 50 , "C" : 100 , "D" : 500 , "M" : 1000}
        
        for i in range(len(s)):
            if(i > 0 and s[i] in rule and s[i - 1] == rule[s[i]]):
                val += num[s[i]] - (num[s[i - 1]] * 2)
            else:
                val += num[s[i]]
                
        return val