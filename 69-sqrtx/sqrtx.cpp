class Solution {
public:
    int mySqrt(int num) {
        if(num == 1)
		return 1;
        int l = 0 , r = num;
        int ans = 0;
        while(l < r){
            int m = (l + r) / 2;
            if(m > (num / m))
                r = m;
            else{
                ans = m;
                l = m + 1;
            }
        }
        return ans;
    }
};