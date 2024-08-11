class Solution {
public:
    vector<vector<int>> mat;

    void createMatrix(int n) {
        int size = n * 3;
        mat = vector<vector<int>>(size, vector<int>(size, 0));
    }
    // '/'
    void bSlash(int i , int j){
        i = i * 3 , j = j * 3;
        mat[i][j + 2] = 1;
        mat[i + 1][j + 1] = 1;
        mat[i + 2][j] = 1;
    }

    void fSlash(int i , int j){
        i = i* 3, j = j * 3;
        mat[i][j] = 1;
        mat[i + 1][j + 1] = 1;
        mat[i + 2][j + 2] = 1;
    }
    int count = 0;
    int getNextCount(){
        count++;
        return count;
    }

    void mapIsland(int i , int j , int& m , int& num){
        if(i < 0 || j < 0 || i >= m || j >= m ||mat[i][j] != 0)
            return;
        
        mat[i][j] = num;
        mapIsland(i + 1 , j , m , num);
        mapIsland(i , j + 1 , m , num);
        mapIsland(i , j - 1 , m , num);
        mapIsland(i - 1 , j , m , num);
        return ;
    }

    int regionsBySlashes(vector<string>& grid) {
        int n = grid.size();
        count = 0;
        createMatrix(n);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                switch (grid[i][j]) {
                    case '/':
                        bSlash(i , j);
                        break;
                    case '\\':
                        fSlash(i , j);
                        break;
                }
            }
        }
        int m = mat.size();
        for(int i=0;i<m;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j] == 0){
                    int islandNum = getNextCount();
                    mapIsland(i , j , m , islandNum);
                }
            }
        }
        return count;
    }
};