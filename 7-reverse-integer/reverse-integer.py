class Solution:
    def reverse(self, x: int) -> int:
        l = str(x)
        q = 0
        if(l[0] == '-'):
            q = 1
        s = ""    
        if(q == 1):
            a = l.split('-')
            s = a[1]
        else:
            s = l
            
        val = 0
        
        if(q == 1):
            val = int('-' + str(int(s[::-1])))
        else:
            val = int(str(int(s[::-1])))
            
        if(val >= (2 ** 31) - 1 or val <= -2 ** 31):
            return (0)
        else:
            return val