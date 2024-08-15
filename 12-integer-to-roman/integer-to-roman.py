class Solution:
    def intToRoman(self, num: int) -> str:
        
        nums = []
        
        def convert(num):
            i = 0
            while(num > 0):
                n = num % 10
                # global nums
                nums.append(n * (10 ** i))
                i += 1
                num = int(num / 10)
        
        convert(num)
        # print(nums[::-1])
        mp = {1 : 'I' , 2 : "II" , 3: "III" , 4: "IV" , 5: "V" , 6: "VI", 7: "VII", 8: "VIII" , 9: "IX" , 10: "X" , 50 : "L" , 100: "C" , 500: "D" , 1000 : "M"}
        
        res = ""
        
        vlv = [1000 , 500 , 100 , 50 , 10 , 5 , 1]
        
        def solve(i):
            # print(i , end=" ")
            for v in vlv:
                if(v == 1000 and i == 900):
                        return "CM"
                elif(v == 500 and i == 400):
                        return "CD"
                elif(v == 100 and i == 90):
                        return "XC"
                elif(v == 50 and i == 40):
                        return "XL"
                elif(v == 10 and i == 9):
                    return "IX"
                elif(v == 5 and i == 4):
                    return "IV"
                
                if(i % v == 0):
                    # times = i // v
                    return mp[i] if(i in mp) else (i // v) * mp[v]
                    # return times * mp[v]
                elif(i / v >= 1):
                    return mp[v] + solve(i % v)
        
        for i in nums[::-1]:
            if(i == 0):
                continue
            else:
                res += solve(i)
        # print()
        return res