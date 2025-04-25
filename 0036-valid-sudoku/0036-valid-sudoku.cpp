class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        if(board.empty()){
            return false;
        }

        map<pair<int,int>, unordered_set<char>> squares;

        // checking column duplicates
        unordered_map<int, unordered_set<char>> columnCharMap;

        // should go 9 times for both loops
        for(int i = 0; i < board.size(); ++i){
            unordered_set<char> rowCharSet;
            for(int j = 0; j < board[i].size(); ++j){
                if(board[i][j] == '.'){
                    continue;
                }

                // check if duplicate value in row
                if(rowCharSet.find(board[i][j]) != rowCharSet.end()){
                    return false; // invalid board
                }
                rowCharSet.insert(board[i][j]);
                

                // check column duplicates
                if(columnCharMap.find(j) != columnCharMap.end() && columnCharMap[j].find(board[i][j]) != columnCharMap[j].end()){
                    return false;
                }
                columnCharMap[j].insert(board[i][j]);

                // check 3x3 duplicates
                // NEED TO REDO THIS 3X3 PORTION
                pair<int, int> squareKey = {i / 3, j / 3};
                if (squares[squareKey].count(board[i][j])) {
                    return false;
                }
                squares[squareKey].insert(board[i][j]);
            }
        }

        return true; // valid board
    }
};
