class Solution {
public:
    //TC : O(n + sqrt(min(a , b))) | where a , b are the upper limit numerator and Denominator
    //SC : O(n)


    //O(sqrt(min(n , m)))
    pair<int,int> commonFactor(int n , int m){
        int t = min(abs(n) , abs(m));
        int i = t;
        if(n % i == 0 && m % i == 0){n /= i , m /= i;return {n , m};}
        int flag = 0;
        i = sqrt(i);
        //cout<<"SQ"<<i<<" " <<t<<" "<<n<<" :"<<m<<endl;
        while(i > 1){
            while(n % i == 0 && m % i == 0){n /= i , m /= i;}
            // if()
            //t = min(abs(n) , abs(m));
            i--;
        }

        return {n , m};
    }

    string fractionAddition(string exp) {
        int n = exp.size();
        if(n == 0) return "0/0";
        if(exp[0] != '-'){
            exp = "+" + exp;
            n++;
        }

        int deno = 1;
        vector<char> symbols = {'-' , '+' , '/'};
        vector<int> mem;
        //O(n * 3 ~ n)
        for(int i=0;i<n;i++){
            //cout<<i<<endl;
            if(!count(symbols.begin() , symbols.end() , exp[i])){
                int num = exp[i] - 48;
                if(exp[i - 1] == '/') deno *= num , mem.push_back(num);
                else if(exp[i - 1] == '+') mem.push_back(num);
                else if(exp[i - 1] == '-') mem.push_back(-1 * num);
                else mem.pop_back() , mem.push_back(exp[i - 2] == '-' ? -10 : 10);
            }
        }

        int nume = 0;
        deno = 1;
        for(int i=1;i<mem.size();i += 2){
            deno *= mem[i];
        }
        for(int i=1;i<mem.size();i+=2){
            int x = deno / mem[i];
            nume += x * mem[i - 1];
        }
        if(nume == 0) return "0/1";

        //for(auto a : mem) cout<<a<<" ";
        auto f = commonFactor(nume, deno);
        //cout<<nume<<" "<<deno<<endl;
        //cout<<f.first<<" "<<f.second<<endl;

        if(f.second == 1) return to_string(f.first) + "/1";
        else return to_string(f.first) + "/" + to_string(f.second);
        //return "";
    }   
};