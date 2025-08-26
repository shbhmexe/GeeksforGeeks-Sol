//Question 381
class Solution {
  public:
    vector<vector<bool>>board;
    bool iCanPlace(int row,int column){
        //check straigh m koi nhi
        for(int i=row;i>=0;i--){
            if(board[i][column]){
                return false;
            }
        }
        
        //check diagonnal-left
        for(int i=row,j=column;i>=0 && j>=0;i--,j--){
            if(board[i][j]){
                return false;
            }
        }
        //check digaonal -right
         for(int i=row,j=column;i>=0 && j<board.size();i--,j++){
            if(board[i][j]){
                return false;
            }
        }
     return true;   
        
    }
    void pos(int row,int n,vector<int>placements,vector<vector<int>>&ans,vector<vector<bool>>&board){
        if(row>=n){
            ans.push_back(placements);
            return;
        }
        
        for(int column=0;column<n;column++){
            if(iCanPlace(row,column)){
                board[row][column]=1;
                placements.push_back(column+1);
                pos(row+1,n,placements,ans,board);
                placements.pop_back();
                board[row][column]=0;
            }
        }
    }
    vector<vector<int>> nQueen(int n) {
        // code here
        int row=0;
          board = vector<vector<bool>>(n, vector<bool>(n, false));
        vector<int>placements;
        vector<vector<int>>ans;
        pos(row,n,placements,ans,board);
        
  return ans;  }
};

