class WordDictionary {
    struct Node {
        Node* children[26] = {};
        bool end = false;
    };
    Node* root = new Node();

    bool dfs(Node* node, string& word, int i) {
        if (i == word.size()) return node->end;
        if (word[i] == '.') {
            for (auto c : node->children)
                if (c && dfs(c, word, i + 1)) return true;
            return false;
        }
        int idx = word[i] - 'a';
        if (!node->children[idx]) return false;
        return dfs(node->children[idx], word, i + 1);
    }

public:
    WordDictionary() {}

    void addWord(string word) {
        Node* cur = root;
        for (char c : word) {
            int i = c - 'a';
            if (!cur->children[i]) cur->children[i] = new Node();
            cur = cur->children[i];
        }
        cur->end = true;
    }

    bool search(string word) {
        return dfs(root, word, 0);
    }
};