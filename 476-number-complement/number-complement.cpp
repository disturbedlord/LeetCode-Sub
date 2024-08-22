class Solution {
public:
    int findComplement(int num) {
        int res = 0;
        int p = 0;
        while(num > 0){
            int x = num & 1;
            if(!x){
                int y = pow(2 , p);
                res = res | y; 
            }
            p++;
            num = num >> 1;
        }

        return res;
    }
};