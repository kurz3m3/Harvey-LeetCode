using namespace std;

class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        if (board.empty() || word.empty()) return false;
        
        int rows = board.size();
        int cols = board[0].size();
        
        // Create a visited array
        vector<vector<bool>> visited(rows, vector<bool>(cols, false));
        
        // Check every cell as a potential starting point
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if (board[i][j] == word[0]) {
                    if (checkAdjacentLetters(board, visited, word, 0, i, j)) {
                        return true;
                    }
                }
            }
        }
        return false;
    }

private:
    bool checkAdjacentLetters(vector<vector<char>>& board, vector<vector<bool>>& visited, 
                            string word, int index, int row, int col) {
        // Base case: if we've matched the entire word
        if (index == word.size()) {
            return true;
        }

        // Check bounds and if cell is visited or doesn't match
        if (row < 0 || row >= board.size() || col < 0 || col >= board[0].size() ||
            visited[row][col] || board[row][col] != word[index]) {
            return false;
        }

        // Mark current cell as visited
        visited[row][col] = true;

        // Check all four directions
        bool found = checkAdjacentLetters(board, visited, word, index + 1, row + 1, col) ||  // Down
                     checkAdjacentLetters(board, visited, word, index + 1, row - 1, col) ||  // Up
                     checkAdjacentLetters(board, visited, word, index + 1, row, col + 1) ||  // Right
                     checkAdjacentLetters(board, visited, word, index + 1, row, col - 1);    // Left

        // Backtrack: unmark the cell so it can be used in other paths
        visited[row][col] = false;

        return found;
    }
};