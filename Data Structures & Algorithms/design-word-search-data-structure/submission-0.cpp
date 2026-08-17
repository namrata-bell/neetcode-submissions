class WordDictionary {
    struct Node {
        Node* child[26];
        bool end;

        Node() {
            end = false;
            for (int i = 0; i < 26; i++)
                child[i] = nullptr;
        }
    };

    Node* root;

    bool dfs(string& word, int i, Node* cur) {
        if (i == word.size())
            return cur->end;

        if (word[i] != '.') {
            int j = word[i] - 'a';

            if (cur->child[j] == nullptr)
                return false;

            return dfs(word, i + 1, cur->child[j]);
        }

        for (int j = 0; j < 26; j++) {
            if (cur->child[j] != nullptr) {
                if (dfs(word, i + 1, cur->child[j]))
                    return true;
            }
        }

        return false;
    }

public:
    WordDictionary() {
        root = new Node();
    }

    void addWord(string word) {
        Node* cur = root;

        for (int i = 0; i < word.size(); i++) {
            int j = word[i] - 'a';

            if (cur->child[j] == nullptr)
                cur->child[j] = new Node();

            cur = cur->child[j];
        }

        cur->end = true;
    }

    bool search(string word) {
        return dfs(word, 0, root);
    }
};