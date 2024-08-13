class Solution {
public:
    vector<vector<int>> cloneGrid(int n, int m) {
        return vector<vector<int>>(n, vector<int>(m, 0));
    }

    void print(vector<vector<int>>& grid) {
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[i].size(); j++) {
                cout << grid[i][j] << " ";
            }
            cout << endl;
        }
    }

    bool validateUnique(int i,int j , vector<vector<int>> g){
        vector<int> seen = vector<int>(9 , 0); //O(9)
        for(int a=i;a<i+3;a++){ //O(9) ~ O(1)
            for(int b=j;b<j+3;b++){
                int k = g[a][b];
                if(k >= 10)return 0;
                if(k == 0)return 0;
                if(seen[k-1])return 0;
                seen[k - 1] = 1;

            }
        }

        return 1;
    }

    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int n = grid.size();    // no of rows
        int m = grid[0].size(); // no of cols
        auto row = cloneGrid(n, m);//O(n*m)
        auto col = cloneGrid(n, m);//O(n*m)
        int res = 0;

        if (n < 3 || m < 3)
            return 0;

        // find RowSum
        for (int i = 0; i < n; i++)
            row[i][0] = grid[i][0]; // populate First Row //O(n)
        for (int i = 0; i < n; i++) { //O(n*m)
            for (int j = 1; j < m; j++) {
                row[i][j] = row[i][j - 1] + grid[i][j];
                if (j >= 3) {
                    row[i][j] -= grid[i][j - 3];
                }
            }
        }

         //print(row);

        // find ColSum
        for (int i = 0; i < m; i++)
            col[0][i] = grid[0][i]; // populate first Column //O(m)
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < m; j++) { //O(n*m)
                col[i][j] = col[i - 1][j] + grid[i][j];
                if (i >= 3) {
                    col[i][j] -= grid[i - 3][j];
                }
            }
        }
         //print(col);

        for (int i = 0; i <= n - 3; i++) { //O(n * m * 9)
            for (int j = 0; j <= m - 3; j++) { //O(n*m * 9)
                 //cout<<i<<":"<<j<<endl;
                int diag1 =
                    grid[i][j] + grid[i + 1][j + 1] + grid[i + 2][j + 2];
                 //cout<<diag1<<" ";
                int diag2 = grid[i][j + 2] + grid[i + 1][j + 2 - 1] +
                            grid[i + 2][j + 2 - 2];
                 //cout<<diag2<<" ";
                int rowS =
                    row[i][j + 2] + row[i + 1][j + 2] + row[i + 2][j + 2];
                int colS =
                    col[i + 2][j] + col[i + 2][j + 1] + col[i + 2][j + 2];

                                         //cout<<rowS<<" "<<colS<<" ";
                                         //cout<<row[i][j + 2]<<"|"<<row[i+1][j + 2]<<"|"<<row[i+2][j+2]<<" ";
                                         //cout<<col[i+2][j]<<"|"<<col[i+2][j+1]<<"|"<<col[i+2][j+2]<<" ";
                bool X = row[i][j + 2] == row[i + 1][j + 2] && row[i+1][j+2] == row[i + 2][j + 2];
                bool Y = col[i + 2][j] == col[i + 2][j + 1] && col[i+2][j+1] == col[i + 2][j + 2];
                //cout<<X<<" L "<<Y<<" ";
                if (X && Y && validateUnique(i,j,grid)) {
                    if (rowS == colS && rowS + colS == 90 && diag1 == diag2 &&
                        diag1 + diag2 == 30)
                        res++;
                }
            }
        }

        //TC : O(n*m)
        //SC : O(n*m)

        return res;
    }
};