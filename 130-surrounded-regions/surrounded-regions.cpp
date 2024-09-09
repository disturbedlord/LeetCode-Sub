class Solution {
public:

    void markAllNonVisitable(int i , int j , vector<vector<char>>& board){
        if(i < 0 || j < 0 || i >= board.size() || j >= board[0].size() || board[i][j] == 'X' || board[i][j] == 'N') return;
        //cout<<i<<"-"<<j<<endl;
        board[i][j] = 'N';
        //up
        markAllNonVisitable(i - 1 , j , board);
        //left
        markAllNonVisitable(i , j - 1 , board);
        //right
        markAllNonVisitable(i , j + 1 , board);
        //down
        markAllNonVisitable(i + 1 , j , board);
    }

    void solve(vector<vector<char>>& board) {
        int n = board.size(); // row
        int m = board[0].size(); //col
        vector<pair<int,int>> zero = vector<pair<int,int>>();
        vector<vector<int>> clone = vector<vector<int>>(n , vector<int>(m , 0));

        // find all corner O
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if((i == 0 || i == n - 1 || j == 0 || j == m - 1) && board[i][j] == 'O'){
                    zero.push_back({i , j});
                }
                //clone[i][j] = board[i][j] == 'O' ? 1 : 0;
            }
        }

        for(auto i : zero){
            //cout<<i.first<< " "<<i.second<<endl;
            markAllNonVisitable(i.first , i.second , board);
        }


        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j] == 'N') board[i][j] = 'O';
                else if(board[i][j] == 'O') board[i][j] = 'X';
            }
        }
    }
};