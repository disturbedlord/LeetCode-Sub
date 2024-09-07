class Solution {
public:

    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int res = 0;
        queue<vector<int>> q;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j] == 2) q.push({i , j , 0});
            }
        }

        while(!q.empty()){
            auto front = q.front();
            int i = front[0] , j = front[1] , k = front[2];
            q.pop();
            if(i + 1 < n && grid[i + 1][j] == 1)grid[i + 1][j] = -(k + 1) , q.push({i + 1 , j , k + 1});
            if(j + 1 < m && grid[i][j + 1] == 1)grid[i][j + 1] = -(k + 1) , q.push({i , j + 1 , k + 1});
            if(i - 1 > -1 && grid[i - 1][j] == 1)grid[i - 1][j] = -(k + 1) , q.push({i - 1 , j , k + 1});
            if(j - 1 > -1 && grid[i][j - 1] == 1)grid[i][j - 1] = -(k + 1) , q.push({i , j - 1 , k + 1});
        }

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j] == 1){
                    return -1;
                }
                if(grid[i][j] < 0)
                res = max(abs(grid[i][j])  , res);
            }
        }

        return res;
    }
};