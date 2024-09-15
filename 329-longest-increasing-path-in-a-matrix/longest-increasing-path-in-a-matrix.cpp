typedef vector<vector<int>> MATRIX;
class Solution {
public:

    int dfs(MATRIX& matrix , MATRIX& visited , int i , int j , int n , int m , int prev){
        if(i < 0 || j < 0 || i >= n || j >= m || matrix[i][j] <= prev || visited[i][j] == -2) return 0;

        if(visited[i][j] != -1) return 1 + visited[i][j];

        visited[i][j] = -2;
        int mx = 0;
        //top
        int top = dfs(matrix , visited , i - 1 , j , n , m , matrix[i][j]);
        mx = max(mx , top);
        //left
        int left = dfs(matrix , visited , i , j - 1 , n , m , matrix[i][j]);
        mx = max(mx , left);
        //Down
        int down = dfs(matrix , visited , i + 1 , j , n , m , matrix[i][j]);
        mx = max(mx , down);
        //right
        int right = dfs(matrix , visited , i , j + 1 , n , m , matrix[i][j]);
        mx = max(mx , right);

        visited[i][j] = mx;
        return 1 + visited[i][j];
    }

    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        int res = 0;
        vector<vector<int>> visited = MATRIX(n , vector<int>(m , -1));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(visited[i][j] == -1){
                    dfs(matrix , visited , i , j , n , m , -1);
                }
            }
        }

        // for(int i=0;i<n;i++){
        //     for(int j=0;j<m;j++){
        //         cout<<visited[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }


        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                res = max(res , visited[i][j] + 1);
            }
        }
        return res;
    }
};