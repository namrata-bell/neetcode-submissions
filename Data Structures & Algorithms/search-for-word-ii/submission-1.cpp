class Solution {
    struct Trie {
        Trie* child[26]{};
        int index = -1;
    };

    Trie* root = new Trie();
    vector<string> ans;
    vector<string> words;
    vector<vector<char>> board;
    int m, n;

    void dfs(int r, int c, Trie* node) {
        if (r < 0 || c < 0 || r >= m || c >= n || board[r][c] == '#')
            return;

        int x = board[r][c] - 'a';
        Trie* next = node->child[x];

        if (!next) return;

        if (next->index != -1) {
            ans.push_back(words[next->index]);
            next->index = -1;
        }

        char ch = board[r][c];
        board[r][c] = '#';

        dfs(r + 1, c, next);
        dfs(r - 1, c, next);
        dfs(r, c + 1, next);
        dfs(r, c - 1, next);

        board[r][c] = ch;
    }

public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        this->board = board;
        this->words = words;
        m = board.size();
        n = board[0].size();

        for (int i = 0; i < words.size(); i++) {
            Trie* cur = root;

            for (char ch : words[i]) {
                int x = ch - 'a';

                if (!cur->child[x])
                    cur->child[x] = new Trie();

                cur = cur->child[x];
            }

            cur->index = i;
        }

        for (int r = 0; r < m; r++)
            for (int c = 0; c < n; c++)
                dfs(r, c, root);

        return ans;
    }
};