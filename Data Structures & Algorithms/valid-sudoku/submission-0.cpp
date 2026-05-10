class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_set<string> st;

        for (int r = 0; r < 9; r++) {
            for (int c = 0; c < 9; c++) {

                if (board[r][c] == '.') continue;

                string row = string(1, board[r][c]) + "row" + to_string(r);
                string col = string(1, board[r][c]) + "col" + to_string(c);
                string box = string(1, board[r][c]) + "box" + 
                             to_string(r / 3) + to_string(c / 3);

                if (st.count(row) || st.count(col) || st.count(box)) {
                    return false;
                }

                st.insert(row);
                st.insert(col);
                st.insert(box);
            }
        }

        return true;
    }
};