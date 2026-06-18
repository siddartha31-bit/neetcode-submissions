class Solution {
    struct Node {
        Node* children[26] = {};
        string word = "";
    };

    void addWord(Node* root, string& w) {
        Node* cur = root;
        for (char c : w) {
            int i = c - 'a';
            if (!cur->children[i]) cur->children[i] = new Node();
            cur = cur->children[i];
        }
        cur->word = w;
    }

    void dfs(vector<vector<char>>& board, int r, int c, Node* node, vector<string>& res) {
        if (r < 0 || c < 0 || r >= (int)board.size() || c >= (int)board[0].size()) return;
        char ch = board[r][c];
        if (ch == '#') return;
        int i = ch - 'a';
        if (!node->children[i]) return;
        node = node->children[i];
        if (node->word != "") {
            res.push_back(node->word);
            node->word = "";
        }
        board[r][c] = '#';
        dfs(board, r+1, c, node, res);
        dfs(board, r-1, c, node, res);
        dfs(board, r, c+1, node, res);
        dfs(board, r, c-1, node, res);
        board[r][c] = ch;
    }

public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        Node* root = new Node();
        for (auto& w : words) addWord(root, w);
        vector<string> res;
        for (int r = 0; r < (int)board.size(); r++)
            for (int c = 0; c < (int)board[0].size(); c++)
                dfs(board, r, c, root, res);
        return res;
    }
};