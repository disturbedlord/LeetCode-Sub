class Solution:
    def plusOne(self, digits: List[int]) -> List[int]:
        val = 1
        num = ""
        for i in digits:
            num += str(i)
            
        num = eval(num)
        num += 1
        num = list(str(num))
        num  = [int(x) for x in num]
        return num