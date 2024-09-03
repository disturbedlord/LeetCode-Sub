class Solution {
public:
    int fib(int n) {
        int f0 = 0 , f1 = 1;
        if(n == 0) return 0;
        if(n == 1) return 1;
        n -= 1;
        while(n > 0){
            int t = f0;
            f0 = f1;
            f1 += t;
            n--;
        }

        return f1;
    }
};