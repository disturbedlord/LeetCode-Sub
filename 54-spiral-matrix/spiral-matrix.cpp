class Solution {
public:

    vector<pair<int,int>> directions = {{0 , 1} , {1 , 0} , {-1 , 0}, {0 , -1}};
    int next = 0;
    pair<int,int> nextStep(){
        int nn = next;
        next ++;
        next %= 4;
        return directions[nn];
    }

    vector<int> spiralOrder(vector<vector<int>>& mat) {
        next = 0;
        int n = mat.size();
        int m = mat[0].size();
        if(n == 0 && m == 0)return {};
        vector<vector<int>> seen = vector<vector<int>>(n , vector<int>(m , 0));
        vector<int> res = vector<int>();
        //res[0] = mat[0][0];
        //seen[0][0] = 1;
        int idx = 0;
        int x = 0 , y = 0;
        auto nStep = nextStep();
        x = nStep.first, y = nStep.second;
        int posX = 0 , posY = 0;
        pair<int,int> prev = {0,0};
        while(idx < (n * m)){
            if((posX >= n || posX < 0 || posY >= m || posY < 0) || seen[posX][posY]){
                nStep = nextStep();
                x = nStep.first;
                y = nStep.second;
                posX = prev.first;posY = prev.second;
                posX += x ; posY += y;
                continue;
            }
            //cout<<posX<<" : "<<posY<<endl;
            res.push_back(mat[posX][posY]);
            seen[posX][posY] = 1;
            prev = {posX , posY};
            posX += x;
            posY += y;
            idx++;
        }

        return res;
    }
};