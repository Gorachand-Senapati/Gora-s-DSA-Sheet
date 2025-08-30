//my method of solve sudoku need only is safe function
class Solution {
public:
    // Check if placing board[row][col] is valid
    bool isSafe(vector<vector<char>>& board, int row, int col, char dig) {
        // Row check
        for (int j = 0; j < 9; j++) {
            if (board[row][j] == dig && j != col) {
                return false;
            }
        }
        // Column check
        for (int i = 0; i < 9; i++) {
            if (board[i][col] == dig && i != row) {
                return false;
            }
        }
        // 3x3 grid check
        int strow = (row / 3) * 3;
        int stcol = (col / 3) * 3;
        for (int i = strow; i < strow + 3; i++) {
            for (int j = stcol; j < stcol + 3; j++) {
                if (board[i][j] == dig && (i != row || j != col)) {
                    return false;
                }
            }
        }
        return true;
    }

    bool isValidSudoku(vector<vector<char>>& board) {
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] != '.') {
                    char dig = board[i][j];
                    if (!isSafe(board, i, j, dig)) {
                        return false;
                    }
                }
            }
        }
        return true;
    }
};
//now if give with set 

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        // Create 9 sets for rows, 9 for columns, and 9 for 3x3 boxes
        // rows[i]   = set of numbers already seen in row i
        // cols[j]   = set of numbers already seen in column j
        // boxes[k]  = set of numbers already seen in box k
        vector<unordered_set<char>> rows(9), cols(9), boxes(9);

        // Traverse each cell of the 9x9 board
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                char c = board[i][j];

                // Skip empty cells
                if (c == '.') continue;

                // 1. Row check → if digit already exists in this row, invalid
                if (rows[i].count(c)) return false;
                rows[i].insert(c);

                // 2. Column check → if digit already exists in this column, invalid
                if (cols[j].count(c)) return false;
                cols[j].insert(c);

                // 3. Box check
                // Each 3x3 box has an index from 0–8.
                // Formula: (i/3)*3 + (j/3)
                //   - i/3 → which row of boxes (0,1,2)
                //   - j/3 → which column of boxes (0,1,2)
                //   - multiply (i/3) by 3 → shift to correct row of boxes
                //   - add (j/3) → choose the box inside that row
                //
                // Example: cell (5,7)
                //   i/3 = 1, j/3 = 2 → boxIndex = 1*3 + 2 = 5
                //   => middle-right 3x3 box
                int boxIndex = (i / 3) * 3 + (j / 3);

                if (boxes[boxIndex].count(c)) return false;
                boxes[boxIndex].insert(c);
            }
        }

        // If no duplicates found in rows, cols, or boxes → board is valid
        return true;
    }
};
