class Solution {
public:

    void findIsland(int i , int j , int&m , int&n , vector<vector<char>>& grid){
        if(i < 0 || j < 0 || i >= m || j >= n || grid[i][j] == '0') return;
        //cout<<i<<":"<<j<<m<<"-"<<n<<endl;
        grid[i][j] = '0';
        //top
        findIsland(i - 1 , j , m , n , grid);
        //down
        findIsland(i + 1 , j , m , n , grid);
        //right
        findIsland(i , j + 1 , m , n , grid);
        //left
        findIsland(i , j - 1 , m , n , grid);
    }

    int numIslands(vector<vector<char>>& grid) {
        int res = 0;
        int m = grid.size();
        int n = grid[0].size();
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j] == '1'){
                    findIsland(i , j , m , n , grid);
                    res ++;
                }
            }
        }

        return res;
    }
};